#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    FILE *fp = fopen("example.c", "r");
    char line[205] = {0}, s[10005] = {0}, record[10005] = {0}, sequence[10005] = {0};
    int top = -1, cflag = 0, qflag1 = 0, qflag2 = 0, flag = 1, cnt = 0, scnt = 0;
    //printf("here\n");
    while (fgets(line, 205, fp) != NULL) {
        //printf("%s\n", line);
        cnt++;
        int len = strlen(line);
        flag = 1;
        for (int i = 0; i < len; i++) {
            if (cflag == 0 && qflag2 == 0 && line[i] == '\'') {
                if (qflag1 == 1) {
                    qflag1 = 0;
                    continue;
                } else {
                    qflag1 = 1;
                    continue;
                }
            } else if (cflag == 0 && qflag1 == 0 && line[i] == '\"') {
                if (qflag2 == 1) {
                    qflag2 = 0;
                    continue;
                } else {
                    qflag2 = 1;
                    continue;
                }
            } else if (qflag1 == 0 && qflag2 == 0 && cflag == 0 && i < (len-1) && line[i] == '/' && line[i+1] == '*') {
                cflag = 1;
                i++;
            } else if (qflag1 == 0 && qflag2 == 0 && cflag == 1 && i < (len-1) && line[i] == '*' && line[i+1] == '/') {
                cflag = 0;
                i++;
            } else if (qflag1 == 0 && qflag2 == 0 && cflag == 0 && i < (len-1) && line[i] == '/' && line[i+1] == '/') {
                //flag = 0;
                break;
            } else if (qflag1 == 0 && qflag2 == 0 && cflag == 0) {
                if (line[i] == '(') {
                    top++;
                    s[top] = line[i];
                    record[top] = cnt;
                    sequence[scnt++] = line[i];
                } else if (line[i] == ')') {
                    if (top < 0 || s[top] != '(') {
                        flag = -1;
                        printf("without matching \'%c\' at line %d\n", line[i], cnt);
                        break;
                    } else {
                        top--;
                        sequence[scnt++] = line[i];
                    }
                } else if (line[i] == '{') {
                    if (top >= 0 && s[top] == '(') {
                        flag = -1;
                        printf("without matching \'%c\' at line %d\n", s[top], record[top]);
                        break;
                    } else {
                        top++;
                        s[top] = line[i];
                        record[top] = cnt;
                        sequence[scnt++] = line[i];
                    }
                } else if (line[i] == '}') {
                    if (top < 0 || s[top] != '{') {
                        flag = -1;
                        printf("without matching \'%c\' at line %d\n", line[i], cnt);
                        break;
                    } else {
                        top--;
                        sequence[scnt++] = line[i];
                    }
                } else {
                    continue;
                }
            }
        }
        if (flag == -1) break;
    }
    if (flag == 1) {
        //printf("in\n");
        if (top >= 0) {
            printf("without matching \'%c\' at line %d\n", s[top], record[top]);
        } else {
            printf("%s\n", sequence);
        }
    } else if (flag == 0) {
        
    } else if (flag == -1) {
        
    }
    fclose(fp);

    return 0;
}
