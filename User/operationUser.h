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

extern sqlite3 *db;

char *addUser(char *username, char *password1, char *password2);

char *login(char *username, char *password);

list<char *> showUsers();

int deleteUser(char *username, char *password);

void closeUser();

bool initUser();

#endif //MMS_OPERATIONUSER_H
