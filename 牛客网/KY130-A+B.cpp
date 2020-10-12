
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int transform(char word[]) {
    if (strcmp(word, "zero") == 0) return 0;
    else if (strcmp(word, "one") == 0) return 1;
    else if (strcmp(word, "two") == 0) return 2;
    else if (strcmp(word, "three") == 0) return 3;
    else if (strcmp(word, "four") == 0) return 4;
    else if (strcmp(word, "five") == 0) return 5;
    else if (strcmp(word, "six") == 0) return 6;
    else if (strcmp(word, "seven") == 0) return 7;
    else if (strcmp(word, "eight") == 0) return 8;
    else if (strcmp(word, "nine") == 0) return 9;
}

int main() {
    int n1 = 0, n2 = 0, flag = 0;
    char word[20] = {0};
    while (true) {
        n1 = 0, n2 = 0, flag = 0;
        while (true) {
            if (scanf("%s", word) == EOF) {
                flag = 1;
                break;
            }
            if (strcmp(word, "+") == 0) break;
            n1 = n1*10+transform(word);
        }
        while (true) {
            if (scanf("%s", word) == EOF) {
                flag = 1;
                break;
            }
            if (strcmp(word, "=") == 0) break;
            n2 = n2*10+transform(word);
        }
        if (n1 == 0 && n2 == 0) break;
        if (flag == 1) break;

        printf("%d\n", n1+n2);
    }

    return 0;
}
