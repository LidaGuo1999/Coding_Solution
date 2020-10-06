#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int s[105] = {0}, top = -1, flag = 0, in = 0;
    while (scanf("%d", &flag) != EOF) {
        if (flag == -1) break;
        else if (flag == 1) {
            scanf("%d", &in);
            if (top >= 99) printf("error ");
            else s[++top] = in;
        } else if (flag == 0) {
            if (top < 0) printf("error ");
            else {
                printf("%d ", s[top]);
                top--;
            }
        }
    }
    
    return 0;
}
