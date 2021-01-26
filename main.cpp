#include <iostream>
#include "main.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    UserTable *table=new UserTable();
    table->insertUser(new User((char *)"1",(char *)"yxl",(char *)"123456"));//const
    table->insertUser(new User((char *)"12",(char *)"wy",(char *)"123456"));
    User *yxl=table->selectUser((char *)"yxl",(char *)"123456");
    User *wy=table->selectUser((char *)"wy",(char *)"123456");
    cout<<yxl->getUserid()<<"  "<<wy->getUserid()<<endl;
    cout<<table->deleteUser((char *)"yxl",(char *)"123456")<<endl;
    cout<<table->selectUser((char *)"yxl",(char *)"123456")<<endl;
    return 0;
}
