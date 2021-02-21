//
// Created by yxl on 2021/1/29.
//

#ifndef MMS_OPERATIONUSER_H
#define MMS_OPERATIONUSER_H

#include "iostream"
#include "cstring"
#include <list>

using namespace std;

#include "../Tools/tools.h"
#include "sqlite3.h"

//extern UserTable *users;
//extern UserTable users;

extern sqlite3 *db;//连接数据库

char *addUser(char *username, char *password1, char *password2);//添加用户

char *login(char *username, char *password);//登录

list<char *> showUsers();//遍历用户名

int deleteUser(char *username, char *password);//删除用户

void closeUser();//关闭用户缓存

bool initUser();//初始化用户缓存

#endif //MMS_OPERATIONUSER_H
