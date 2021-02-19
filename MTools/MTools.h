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

extern map<string, string> powers;

extern list<string> dbnames;

extern sqlite3 *pdb;

extern map<string,string>::iterator pit;

extern mutex *lock;

bool initMms();

bool closeMms();

bool givePower(string userid,string tableid);

bool updatePower(string userid,string tableid);

int getPower(char *userid, char *tableid,int doing);

#endif //MMS_MTOOLS_H
