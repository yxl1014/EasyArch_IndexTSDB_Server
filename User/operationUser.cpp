//
// Created by yxl on 2021/1/29.
//
#include "operationUser.h"

UserTable *users=new UserTable;

char *addUser(char *username, char *password1, char *password2) {
    if (username == nullptr || password1 == nullptr || password2 == nullptr ||
        !strcmp(username, "") || !strcmp(password1, "") || !strcmp(password2, "")) {
        return nullptr;
    }
    if (strcmp(password1, password2)) {
        return nullptr;
    }
    char *userid = nullptr;
    if (0/*李英凯插入数据*/) {
        return nullptr;
    }
    userid = "1";//=访问李关系型数据库返回一个 userid(select userid from user where username= username and password = password1
    users->insertUser(new User(userid, username, password1));
    return userid;
}

char *login(char *username, char *password) {
    if (username == nullptr || password == nullptr ||
        !strcmp(username, "") || !strcmp(password, "")) {
        return nullptr;
    }
    User *user = users->selectUser(username, password);
    if (user == nullptr) {
        return nullptr;
    }
    return user->getUserid();
}

list<char *> showUsers() {
    return users->selectAllUsername();
}

int deleteUser(char *username, char *password){
    if (username == nullptr || password == nullptr ||
        !strcmp(username, "") || !strcmp(password, "")) {
        return false;
    }
    if (0/*李英凯插入数据*/) {
        return false;
    }
    return users->deleteUser(username,password);
}

void closeall(){
    delete(users);
}