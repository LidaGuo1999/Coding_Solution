#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;



int main() {
    char pre = 0, c = 0, start = 0;
    int flag = 0;
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            if (flag == 1 && c > start) {
                for (char t = start+1; t < c; t++) {
                    printf("%c", t);
                }
                printf("%c", c);
            } else if (flag == 0) {
                printf("%c", c);
            } else {
                printf("%c%c", pre, c);
            }
            flag = 0;
        } else if (c >= 'A' && c <= 'Z') {
            if (flag == 2 && c > start) {
                for (char t = start+1; t < c; t++) {
                    printf("%c", t);
                }
                printf("%c", c);
            } else if (flag == 0) {
                printf("%c", c);
            } else {
                printf("%c%c", pre, c);
            }
            flag = 0;
        } else if (c >= '0' && c <= '9') {
            if (flag == 3 && c > start) {
                for (char t = start+1; t < c; t++) {
                    printf("%c", t);
                }
                printf("%c", c);
            } else if (flag == 0) {
                printf("%c", c);
            } else {
                printf("%c%c", pre, c);
            }
            flag = 0;
        } else if (c == '-') {
            if (pre == '-') printf("%c", pre);
            start = pre;
            if (start >= 'a' && start <= 'z') flag = 1;
            else if (start >= 'A' && start <= 'Z') flag = 2;
            else if (start >= '0' && start <= '9') flag = 3;
            else flag = 4;
        } else {
            if (flag != 0) printf("%c", pre);
            printf("%c", c);
            flag = 0;
        }
        pre = c;
    }
    
    if (pre == '-') printf("%c", pre);
    printf("\n");

    return 0;
}
