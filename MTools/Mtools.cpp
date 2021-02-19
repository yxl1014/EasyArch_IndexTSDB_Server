//
// Created by yxl on 2021/2/2.
//
#include "MTools.h"


map<string, string> powers;

map<string, string>::iterator pit;

list<string> dbnames;

sqlite3 *pdb;

mutex power_lock;

string insertpowersql(string usertableid, string powermask) {//拼插入语句
    string sql = "insert into powers(usertableid,powermask) values('" + usertableid + "','" + powermask + "');";
    return sql;
}

string updatepowersql(string usertableid, string newpowermask) {//拼更新语句
    string sql = "update powers set powermask = '" + newpowermask + "' where usertableid='" + usertableid + "';";
    return sql;
}

string deletesql(string usertableid) {
    string sql = "delete from powers where usertableid='" + usertableid + "';";
    return sql;
}

bool getdbnames() {
    bool ok = false;

    return ok;
}

static int callback(void *data, int args_num, char **argv, char **argc) {
    string key;
    string value;
    if (args_num == 0) {
        return 0;
    }
    for (int i = 0; i < args_num; i++) {
        if (!strcmp(argc[i], "usertableid")) {
            if (argv[i] != nullptr) {
                key = argv[i];
            }
        }
        if (!strcmp(argc[i], "powermask")) {
            if (argv[i] != nullptr) {
                value = argv[i];
            }
        }
        if ((i + 1) % 2 == 0) {
            power_lock.lock();
            powers[key] = value;
            power_lock.unlock();
        }
    }
    return 0;
}

bool initMms() {
    int rc = sqlite3_open("/data/testsql.db", &pdb);//连接sqlite数据库
    if (rc != SQLITE_OK) {//连接失败则返回初始化失败
        cout << "open sqlite3 fail." << endl;
        return false;
    }
    return true;
}

bool closeMms() {
    powers.clear();
    sqlite3_close(pdb);
    return true;
}

string setPower(string userid, string tableid) {
    string power;
    //TODO:关键点,暂时没有思路
    return power;
}

bool givePower(string userid, string tableid) {
    if (userid.empty() || userid.compare("")//判断是否为空
        || tableid.empty() || tableid.compare("")) {
        return false;
    }
    string key = userid + tableid;//缓存key为id
    power_lock.lock();
    if (powers.count(key)) {//查看这个权限本地有没有
        if (updatePower(userid, tableid))//如果有则变为修改权限
            return true;
        else
            return false;
    }
    power_lock.unlock();

    string value = setPower(userid,tableid);//设置权限

    char *error_msg = nullptr;//sqlite报错提示

    string sql = insertpowersql(key, value);//拼sql语句

    int rc = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, &error_msg);//执行sql语句

    if (rc != SQLITE_OK) {//若执行未成功则输出错误并且返回null，TODO:后期可以改为log
        cout << "Insert failed! Error msg: " << error_msg << endl;//输出数据库操作报错信息
        sqlite3_free(error_msg);
        return false;
    }
    power_lock.lock();
    powers[key] = value;//存入本地
    power_lock.unlock();
    return true;
}

bool updatePower(string userid, string tableid) {
    if (userid.empty() || userid.compare("")//判断是否为空
        || tableid.empty() || tableid.compare("")) {
        return false;
    }
    string key = userid + tableid;//缓存key为id
    string value = setPower(userid,tableid);//设置权限

    char *error = nullptr;

    string sql = updatepowersql(key, value);//拼修改语句

    int rc = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, &error);

    if (rc != SQLITE_OK) {//若执行未成功则输出错误并且返回null，TODO:后期可以改为log
        cout << "Update failed! Error msg: " << error << endl;//输出数据库操作报错信息
        sqlite3_free(error);
        return false;
    }

    power_lock.lock();
    powers[key] = value;//存入本地
    power_lock.unlock();

    return true;
}

int getPower(string userid, string tableid) {
    if (userid.empty() || userid.compare("")//判断是否为空
        || tableid.empty() || tableid.compare("")) {
        return 0;
    }
    string key = userid + tableid;//缓存key为id

    power_lock.lock();//上锁

    if (powers.count(key)) {//判断缓存中有没有
        return atoi(powers[key].c_str());
    }

    char *zErrMsg = nullptr;//接受exec函数返回的信息
    const char *data = "Powers:";
    const string sql = "select usertableid,powermask from powers where usertableid= '" + key + "';";
    int ok = sqlite3_exec(pdb, sql.c_str(), callback, (void *) data, &zErrMsg);//将sqlite中的用户表缓存到本地
    if (ok != 0) {//查询未成功，则报错并退出。
        cout << "failed select:" << zErrMsg << endl;
        sqlite3_close(pdb);
        return 0;
    }

    if (powers.count(key)) {
        return atoi(powers[key].c_str());
    }

    power_lock.unlock();
    return 0;
}

bool deletePower(string userid, string tableid) {
    if (userid.empty() || userid.compare("")//判断是否为空
        || tableid.empty() || tableid.compare("")) {
        return 0;
    }
    string key = userid + tableid;//缓存key为id

    power_lock.lock();//上锁

    if (powers.count(key)) {//判断缓存中有没有
        powers.erase(key);
    }

    char *zErrMsg = nullptr;//接受exec函数返回的信息

    string sql = deletesql(key);//拼delete语句
    int ok = sqlite3_exec(pdb, sql.c_str(), nullptr, nullptr, &zErrMsg);//sqlite执行delete语句
    if (ok != SQLITE_OK) {
        cout << "Delete failed! Error msg: " << zErrMsg << endl;//输出数据库操作报错信息
        sqlite3_free(zErrMsg);
        return false;
    }
    power_lock.unlock();

    return true;
}