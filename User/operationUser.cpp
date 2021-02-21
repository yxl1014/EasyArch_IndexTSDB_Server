//
// Created by yxl on 2021/1/29.
//
#include "operationUser.h"

//0x5591cfcd2eb0
//0x5591cfcd2eb0
extern UserTable *users = nullptr;

sqlite3 *db;

string insertsql(string username, string password) {
    string sql = "insert into users(username,password) values('" + username + "','" + password + "');";
    return sql;
}

string selectsql(string username, string password) {
    string sql = "select * from users where username='" + username + "' and password='" + password + "';";
    return sql;
}

string deletesql(string username, string password) {
    string sql = "delete from users where username='" + username + "' and password='" + password + "';";
    return sql;
}


//callback函数为数据库返回值回调函数
//args_num为查询的数据量，如：若有3个字段查询到有3条数据，则共3*3=9个数据，args_num=9
//argv为数据若第一行数据为1 2 3 ，第二行数据为4 5 6,则argv为1 2 3 4 5 6数组
//argc为字段名，若字段为userid，username，password，一共两条数据，则argc为userid，username，password，userid，username，password数组
static int callback(void *data, int args_num, char **argv, char **argc) {
    User *user = new User;//new一个user类

    if (args_num == 0) {//若无返回数据则直接返回
        return 0;
    }

    for (int i = 0; i < args_num; i++) {//循环遍历数据
        if (!strcmp(argc[i], "userid")) {//若字段名为userid
            if (argv[i] != nullptr) {//且数据不为null
                //cout << argv[i] << endl;
                user->setUserid(argv[i]);//设置用户名
            }
        }
        if (!strcmp(argc[i], "username")) {//同上
            if (argv[i] != nullptr) {
                //cout << argv[i] << endl;
                user->setUsername(argv[i]);
            }
        }
        if (!strcmp(argc[i], "password")) {
            if (argv[i] != nullptr) {
                //cout << argv[i] << endl;
                user->setPassword(argv[i]);
            }
        }
        if ((i + 1) % 3 == 0) {//若一个用户已经设置完毕
            users->insertUser(user);//则将用户存到本地缓存中
            if (args_num != i + 1)//且有多个用户
                user = new User;//则再new一个user类
        }
    }
    return 0;
}

bool initUser() {
    bool isinit = false;
    users = new UserTable();//新建一个用户缓存表

    int rc = sqlite3_open("/data/testsql.db", &db);//连接sqlite数据库
    if (rc != SQLITE_OK) {//连接失败则返回初始化失败
        cout << "open sqlite3 fail." << endl;
        return false;
    }
    char *zErrMsg = nullptr;//接受exec函数返回的信息
    const char *data = "Users:";
    const char *sql = "select * from users";
    int ok = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);//将sqlite中的用户表缓存到本地
    if (ok != 0) {//若执行未成功则返回初始化失败
        cout << "failed select:" << zErrMsg << endl;
        sqlite3_close(db);
        delete (users);
        return false;
    }
    isinit = true;
    return isinit;
}


char *addUser(char *username, char *password1, char *password2) {
    if (username == nullptr || password1 == nullptr || password2 == nullptr ||
        !strcmp(username, "") || !strcmp(password1, "") || !strcmp(password2, "")) {//判断字符串是否为空
        return nullptr;
    }
    if (!!strcmp(password1, password2)) {//判断两次密码相不相同
        return nullptr;
    }
    if (users->containsUsername(username)) {//判断是否重名
        return nullptr;
    }

    char *error_msg = nullptr;//sqlite报错提示

    string sql = insertsql(username, password1);//拼sql语句
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_msg);//执行sql语句
    if (rc != SQLITE_OK) {//若执行未成功则输出错误并且返回null，TODO:后期可以改为log
        cout << "Insert failed! Error msg: " << error_msg << endl;
        sqlite3_free(error_msg);
        return nullptr;
    }

    char *userid = nullptr;
    sql = selectsql(username, password1);//拼sql语句
    rc = sqlite3_exec(db, sql.c_str(), callback, (void *) users, &error_msg);//若添加成功则查询添加用户的id，并且返回
    if (rc != SQLITE_OK) {
        cout << "Select failed! Error msg: " << error_msg << endl;
        sqlite3_free(error_msg);
        return nullptr;
    }
    User *user = users->selectUser(username, password1);
    if (user != nullptr) {//如果查到该user并且不为null
        userid = user->getUserid();//获得加入缓存中的userid，并且返回
    }
    return userid;//返回userid
}

char *login(char *username, char *password) {
    if (username == nullptr || password == nullptr ||
        !strcmp(username, "") || !strcmp(password, "")) {//判断字符串是否为空
        return nullptr;
    }
    User *user = users->selectUser(username, password);//查询，查询到则返回id
    if (user == nullptr) {
        return nullptr;
    }
    return user->getUserid();
}

list<char *> showUsers() {
    return users->selectAllUsername();//查询缓存中所有用户并返回用户名
}

int deleteUser(char *username, char *password) {
    if (username == nullptr || password == nullptr ||
        !strcmp(username, "") || !strcmp(password, "")) {//判断字符串是否为空
        return false;
    }

    char *error_msg = nullptr;//sqlite报错提示
    string sql = deletesql(username, password);
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &error_msg);//执行sql语句
    if (rc != SQLITE_OK) {//若执行未成功则输出错误并且返回null，TODO:后期可以改为log
        cout << "Delete failed! Error msg: " << error_msg << endl;
        sqlite3_free(error_msg);
        return false;
    }
    bool isok=false;

    for(int i=0;i<10;i++){//删除本地缓存，设定删除10次，若删除成功则返回删除成功
        if(users->deleteUser(username, password)){
            isok= true;
            break;
        }
    }

    if(!isok){//若删除失败，则回滚，将user写入数据库
        addUser(username,password,password);
    }

    return isok;//返回是否成功
}

void closeUser() {
    delete (users);//清楚用户表本地缓存
    sqlite3_close(db);//关闭数据库
}

