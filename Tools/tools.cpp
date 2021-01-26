//
// Created by yxl on 2021/1/26.
//

#include "tools.h"


int UserTable::hash(char *username, char *password) {
    int num = 0;
    for (int i = 0; username[i] != '\0'; ++i) {
        num += username[i];
    }
    for (int i = 0; password[i] != '\0'; ++i) {
        num += password[i];
    }
    return num % 100;
}

bool UserTable::insertUser(User *user) {
    int home = this->hash(user->getUsername(), user->getPassword());
    User *temp = users[home];
    bool isok;
    if (temp == NULL) {
        temp = user;
        isok = true;
    } else {
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp = user;
        isok = true;
    }
    return isok;
}

bool UserTable::deleteUser(char *username, char *password) {
    bool isok;
    int home = this->hash(username, password);
    User *temp = users[home];
    if (temp == NULL) {
        isok = false;
    }
    if (temp->getNext() == NULL) {
        if (strcmp(temp->getUsername(), username) && strcmp(temp->getPassword(), password)) {
            free(temp);
            users[home] = NULL;
            isok = true;
        }
    }
    while (temp->getNext() != NULL) {
        User *p = temp->getNext();
        if (strcmp(temp->getUsername(), username) && strcmp(temp->getPassword(), password)) {
            temp = (p->getNext());
            free(p);
            isok = true;
            break;
        }
        temp = temp->getNext();
    }
    return isok;
}

User *UserTable::selectUser(char *username, char *password) {
    User *user = NULL;
    int home = hash(username, password);
    User *temp = users[home];
    if (temp == NULL) {
        user = NULL;
    }
    if (temp->getNext() == NULL) {
        if (strcmp(temp->getUsername(), username) && strcmp(temp->getPassword(), password))
            user = temp;
    }
    while (temp->getNext() != NULL) {
        User *p = temp->getNext();
        if (strcmp(p->getUsername(), username) && strcmp(p->getPassword(), password)) {
            user = p;
        }
        temp=p;
    }
    return user;
}

char *User::getUserid() const {
    return userid;
}

void User::setUserid(char *userid) {
    User::userid = userid;
}

char *User::getUsername() const {
    return username;
}

void User::setUsername(char *username) {
    User::username = username;
}

char *User::getPassword() const {
    return password;
}

void User::setPassword(char *password) {
    User::password = password;
}

User *User::getNext() const {
    return next;
}

void User::setNext(User *next) {
    User::next = next;
}

User::User() {}

User::User(char *userid, char *username, char *password) {
    strcpy(this->userid, userid);
    strcpy(this->username, username);
    strcpy(this->password, password);
}

