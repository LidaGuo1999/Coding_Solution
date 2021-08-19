#include <iostream>
using namespace std;

void fun(char *p) {
    p = "cba";
}

int main() {
    char *p = "abc";
    fun(p);
    cout << p << endl;
    return 0;
}
