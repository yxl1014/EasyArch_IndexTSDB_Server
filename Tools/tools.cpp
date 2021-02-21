//
// Created by yxl on 2021/1/26.
//


#include "tools.h"

int UserTable::hash(char *username, char *password) {//计算hash值
    int num = 0;
    for (int i = 0; username[i] != '\0'; ++i) {//计算用户名每个字符的ascll码，加起来
        num += username[i];
    }
    for (int i = 0; password[i] != '\0'; ++i) {//计算密码每个字符的ascll码，加起来
        num += password[i];
    }
    return num % 100;//模100算出hash值
}

bool UserTable::insertUser(User *user) {//插入用户
    bool isok;

    if (user == nullptr ||//user不为空
        user->getUsername() == nullptr || strcpy(user->getUsername(), "") ||//用户名不为空
        user->getPassword() == nullptr || strcpy(user->getPassword(), "")) {//密码不为空
        return false;
    }

    int home = this->hash(user->getUsername(), user->getPassword());//计算hash值
    //TODO：锁
    //user_lock.lock();
    User *temp = this->users[home];//临时指针指向该链表
    if (temp == nullptr) {//如果该链表为空
        this->users[home] = user;//则该用户为头节点
        isok = true;
    } else {//若不为空
        while (temp->getNext() != nullptr) {//则找到最后一个节点
            temp = temp->getNext();
        }
        temp->setNext(user);//将user尾插入链表
        isok = true;
    }
    //cout<<users->users[home]->getUsername()<<"\t"<<users->users[home]->getPassword()<<endl;
    //user_lock.unlock();
    return isok;
}

bool UserTable::deleteUser(char *username, char *password) {//删除用户
    bool isok;

    if (username == nullptr || strcpy(username, "") ||//用户名不为空
        password == nullptr || strcpy(password, "")) {//密码不为空
        return false;
    }

    int home = this->hash(username, password);//计算hash值
    //TODO：锁
    //user_lock.lock();
    User *temp = this->users[home];//临时指针指向该链表
    if (temp == nullptr) {//该链表为空
        isok = false;//则无该用户
    } else if (temp->getNext() == nullptr) {//若该节点没有第二个节点
        if (strcmp(temp->getUsername(), username) == 0 && strcmp(temp->getPassword(), password) == 0) {//则比较这个头节点是否为该用户
            delete (temp);//找到则删除
            this->users[home] = nullptr;//将链表设为空
            isok = true;
        }
    } else {//若有第二个节点
        while (temp->getNext() != nullptr) {//循环查找该用户
            User *p = temp->getNext();
            if (strcmp(temp->getUsername(), username) == 0 && strcmp(temp->getPassword(), password) == 0) {
                temp->setNext(p->getNext());//将上一个节点指向下一个节点
                delete (p);
                isok = true;
                break;
            }
            temp = temp->getNext();
        }
    }
    //user_lock.unlock();
    return isok;
}

User *UserTable::selectUser(char *username, char *password) {//查询用户
    User *user = nullptr;
    //TODO：锁
    //user_lock.lock();

    if (username == nullptr || strcpy(username, "") ||//用户名不为空
        password == nullptr || strcpy(password, "")) {//密码不为空
        return nullptr;
    }

    int home = hash(username, password);//计算hash值

    User *temp = this->users[home];//临时指针指向该链表

    if (temp == nullptr) {//该链表为空
        user = nullptr;//则无该用户
    } else if (temp->getNext() == nullptr) {//若该节点没有第二个节点
        //cout<<users->users[home]->getUsername()<<"\t"<<users->users[home]->getPassword()<<endl;
        //cout<<temp->getUsername()<<"\t"<<temp->getPassword()<<endl;
        if ((strcmp(temp->getUsername(), username) == 0) &&
            (strcmp(temp->getPassword(), password) == 0))//则比较这个头节点是否为该用户
            user = temp;//是则将user赋值为该用户指针
    } else {//若有第二个节点
        while (temp->getNext() != nullptr) {//循环查找该用户
            User *p = temp->getNext();
            if (strcmp(p->getUsername(), username) == 0 && strcmp(p->getPassword(), password) == 0) {
                user = p;
            }
            temp = p;
        }
    }
    //user_lock.unlock();
    return user;
}

UserTable::UserTable() {}

UserTable::~UserTable() {
    for (int i = 0; i < 100; i++) {
        User *temp = users[i];
        User *next;
        if (temp != nullptr) {
            if (temp->getNext() != nullptr) {
                while (temp != nullptr) {
                    next = temp->getNext();
                    delete (temp);
                    temp = next;
                }
                users[i] = nullptr;
            } else {
                delete (temp);
                users[i] = nullptr;
            }
        }
    }
}

list<char *> UserTable::selectAllUsername() {//遍历所有用户名
    list<char *> list;//定义用户名链表
    for (int i = 0; i < 100; i++) {//循环遍历每一个hash地址
        User *temp = this->users[i];//将temp指针指向该链表
        User *next;//定义下一个节点
        if (temp != nullptr) {//如果该链表头节点不为空执行
            if (temp->getNext() != nullptr) {//如果该链表有第二个节点
                while (temp != nullptr) {//遍历该链表
                    next = temp->getNext();//将next指向下一个节点
                    list.push_back(temp->getUsername());//将用户名从后插入list
                    temp = next;//temp指向下一个
                }
            } else {//如果没有第二个节点
                list.push_back(temp->getUsername());//将用户名从后插入list
            }
        }
    }
    return list;
}

bool UserTable::containsUsername(char *newusername) {
    bool ishave = false;
    for (int i = 0; i < 100; i++) {//循环遍历每一个hash地址

        User *temp = this->users[i];//将temp指针指向该链表
        User *next;//定义下一个节点
        if (temp != nullptr) {//如果该链表头节点不为空执行
            if (temp->getNext() != nullptr) {//如果该链表有第二个节点
                while (temp != nullptr) {//遍历该链表
                    next = temp->getNext();//将next指向下一个节点
                    if (!strcmp(temp->getUsername(), newusername)) {//判断是否重名
                        ishave = true;//重名将ishave设为true
                        i = 100;//退出for循环
                        break;//退出while循环
                    }//若不重名
                    temp = next;//则temp指向下一个
                }
            } else {//如果没有第二个节点
                if (!strcmp(temp->getUsername(), newusername)) {//直接比较是否重名
                    ishave = true;//重名则将ishave设为true，退出循环
                    break;
                }//否则继续循环
            }
        }//否则直接下一条链表
    }
    return ishave;
}

char *User::getUserid() const {
    return userid;
}

void User::setUserid(char *userid) {
    this->userid = (char *) malloc(100);
    memset(this->userid, 0, 100);
    strcpy(this->userid, userid);
}

char *User::getUsername() const {
    return username;
}

void User::setUsername(char *username) {
    this->username = (char *) malloc(100);
    memset(this->username, 0, 100);
    strcpy(this->username, username);
}

char *User::getPassword() const {
    return password;
}

void User::setPassword(char *password) {
    this->password = (char *) malloc(100);
    memset(this->password, 0, 100);
    strcpy(this->password, password);
}

User *User::getNext() const {
    return next;
}

void User::setNext(User *next) {
    User::next = next;
}

User::User() {}

User::User(char *userid, char *username, char *password) {
    this->userid = userid;
    this->username = username;
    this->password = password;
}

User::~User() {
    this->userid = nullptr;
    this->username = nullptr;
    this->password = nullptr;
}

