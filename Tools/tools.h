//
// Created by yxl on 2021/1/26.
//
#ifndef MMS_TOOLS_H
#define MMS_TOOLS_H

#include "cstring"
#include "istream"

using namespace std;

class User {
private:
    char *userid;
    char *username;
    char *password;
    User *next = NULL;
public:
    char *getUserid() const;

    User *getNext() const;

    void setNext(User *next);

    void setUserid(char *userid);

    char *getUsername() const;

    void setUsername(char *username);

    char *getPassword() const;

    void setPassword(char *password);

    User();

    User(char *userid, char *username, char *password);
};

class UserTable {
private:
    User *users[100];

    int hash(char *username, char *password);

public:
    bool insertUser(User *user);

    bool deleteUser(char *username, char *password);

    User *selectUser(char *username, char *password);
};


#endif //MMS_TOOLS_H
