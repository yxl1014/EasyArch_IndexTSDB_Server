#include <iostream>
#include "main.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << getPower("123") << endl;
    Hash *hash=new Hash();
    cout<<hash->hash("qaz","123456")<<endl;
    return 0;
}
