#include <iostream>
#include "main.h"

using namespace std;

int main() {
    cout << addUser((char *)"abc", (char *)"123", (char *)"123") << endl;
    cout << addUser((char *)"bcd", (char *)"456", (char *)"456") << endl;
    cout << "bcd:" << login((char *)"bcd", (char *)"456") << endl;
    list<char *> usernames = showUsers();
    list<char *>::iterator i;
    for (i = usernames.begin(); i != usernames.end(); ++i)
        cout << *i << " ";
    cout << endl;
    deleteUser((char *)"bcd", (char *)"456");
    cout << "bcd:" << login((char *)"bcd", (char *)"456") << endl;
    closeall();
    return 0;
}
