#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    FILE *in = fopen("fcopy.in", "r");
    FILE *out = fopen("fcopy.out", "w");

    char cur;
    int flag = 0; 
    while ((cur = fgetc(in)) != EOF) {
        if (cur == ' ' || cur == '\t') {
            if (flag == 0) {
                fputc(' ', out);
                flag = 1;
            } else {
                flag = 1;
            }
        } else {
            if (flag == 0) {
                fputc(cur, out);
                flag = 0;
            } else {
                fputc(cur, out);
                flag = 0;
            }
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}
