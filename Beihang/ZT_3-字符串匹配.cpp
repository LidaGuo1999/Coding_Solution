
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int handle(char pattern[], char ans[][1005]) {
    int start = -1, end = -1, rtn = 0;
    for (int i = 0; i < strlen(pattern); i++) {
        if (pattern[i] == '[') start = i;
        if (pattern[i] == ']') end = i;
    }
    if (start == -1 || end == -1) {
        for (int i = 0; i < strlen(pattern); i++) ans[0][i] = pattern[i];
        rtn = 1;
    } else {
        for (int j = start+1; j < end; j++) {
            int cnt = 0;
            for (int i = 0; i < start; i++) {
                ans[rtn][cnt++] = pattern[i];
            }
            ans[rtn][cnt++] = pattern[j];
            for (int i = end+1; i < strlen(pattern); i++) {
                ans[rtn][cnt++] = pattern[i];
            }
            rtn++;
        }
    }
    return rtn;
}

bool judge(char w, char p) {
    if (w >= 'A' && w <= 'Z') w = w+'a'-'A';
    if (p >= 'A' && p <= 'Z') p = p+'a'-'A';
    return (w == p);
}

bool isSame(char word[], char pattern[]) {
    int wlen = strlen(word), plen = strlen(pattern);
    int wpos = 0, i = 0;
    for (i = 0; i < plen; i++) {
        if (wpos >= wlen) break;
        if (pattern[i] == '[') {
            int start = i, end = -1;
            for (int j = i+1; j < plen; j++) {
                if (pattern[j] == ']') {
                    end = j;
                    break;
                }
            }
            if (end != -1) {
                int flag = 0;
                for (int k = start+1; k < end; k++) {
                    if (judge(word[wpos], pattern[k])) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) return false;
                else {
                    i = end;
                    wpos++;
                    continue;
                }
            } else {
                if (judge(word[wpos], pattern[i])) {
                    wpos++;
                    continue;
                }
                else return false;
            }
        } else {
            if (judge(word[wpos], pattern[i])) {
                wpos++;
                continue;
            }
            else return false;
        }
    }
    if (wpos == wlen && i == plen) return true;
    else return false;
}

int main() {
    int n;
    char ori[1005][1005], words[1005][1005], ans[1005][1005];
    while (scanf("%d", &n) != EOF) {
        memset(words, 0, sizeof(words)), memset(ans, 0, sizeof(ans)), memset(ori, 0, sizeof(ori));
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            /*strcpy(ori[i], words[i]);
            for (int j = 0; j < strlen(words[i]); j++) {
                if (words[i][j] >= 'A' && words[i][j] <= 'Z') {
                    words[i][j] = words[i][j] - 'A' + 'a';
                }
            }*/
        }
        getchar();
        char pattern[1005] = {0};
        gets(pattern);
        /*for (int j = 0; j < strlen(pattern); j++) {
            if (pattern[j] >= 'A' && pattern[j] <= 'Z') {
                pattern[j] = pattern[j] - 'A' + 'a';
            }
        }*/

        for (int i = 0; i < n; i++) {
            if (isSame(words[i], pattern)) {
                printf("%d %s\n", i+1, words[i]);
            } else {
                continue;
            }
        }
    }

    return 0;
}
