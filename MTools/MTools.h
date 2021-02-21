//
// Created by yxl on 2021/2/2.
//

#ifndef MMS_MTOOLS_H
#define MMS_MTOOLS_H

#include <map>
#include "iostream"
#include <list>
#include <mutex>

using namespace std;

#include "cstring"
#include "mutex"
#include "sqlite3.h"

extern map<string, string> powers;//权限本地缓存

extern list<string> dbnames;//库名链表

extern sqlite3 *pdb;//数据库

extern map<string, string>::iterator pit;//map迭代器

//extern mutex power_lock;//锁

bool initMms();//初始化权限缓存

bool closeMms();//关闭权限缓存

bool givePower(string userid, string tableid, string mask);//赋予权限

bool updatePower(string userid, string tableid, string mask);//更新权限

int getPower(string userid, string tableid);//获取权限掩码

list<bool> containsMask(string userid,string mask);//获取权限

#endif //MMS_MTOOLS_H
