#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char line[1005] = {0};
    int cnt[27] = {0};
    while (fgets(line, 1005, stdin) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                cnt[line[i]-'a']++;
            }
        }
    }
    
    /*for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
    printf("\n");*/
    int cur_max = 0;
    for (int i = 0; i < 26; i++) cur_max = cnt[i]>cur_max ? cnt[i] : cur_max;
    //printf("max:%d\n", cur_max);

    for (int i = cur_max; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            if (cnt[j] >= i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) printf("%c", 'a'+i);
    printf("\n");

    return 0;
}
