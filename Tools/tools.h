//
// Created by yxl on 2021/1/26.
//
#ifndef MMS_TOOLS_H
#define MMS_TOOLS_H

#include "cstring"
#include "iostream"
#include <mutex>
#include <list>

using namespace std;

class User {
private:
    char *userid;//用户id
    char *username;//用户名
    char *password;//用户密码
    User *next;//链表指针
public:

    char *getUserid() const;

    void setUserid(char *userid);

    char *getUsername() const;

    void setUsername(char *username);

    char *getPassword() const;

    void setPassword(char *password);

    User *getNext() const;

    void setNext(User *next);

    User();

    User(char *userid, char *username, char *password);

    ~User();
};

class UserTable {
private:
    int hash(char *username, char *password);//计算hash值

public:
    User *users[100];
    //mutex user_lock;

    list<char *> selectAllUsername();//遍历所有用户名

    bool insertUser(User *user);//插入用户

    bool deleteUser(char *username, char *password);//删除用户

    bool containsUsername(char *newusername);//判断重名

    User *selectUser(char *username, char *password);//查询用户

    UserTable();

    ~UserTable();
};

#endif //MMS_TOOLS_H
