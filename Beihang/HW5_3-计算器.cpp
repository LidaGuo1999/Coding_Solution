#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void truncate(char ex[], char tex[]) {
    int len = strlen(ex), cnt = 0;
    for (int i = 0; i < len; i++) {
        if (ex[i] == '=') break;
        if (ex[i] != ' ') tex[cnt++] = ex[i];
    }
    return ;
}

int main() {
    char ex[10000] = {0}, tex[10000] = {0}, s[10000] = {0};
    int post[10000] = {0};
    int mark[10000] = {0};
    int cal[10000] = {0};
    fgets(ex, 10000, stdin);
    truncate(ex, tex);
    //printf("tex:%s\n", tex);
    int len = strlen(tex), mflag = 0, pcnt = 0, top = -1, ctop = -1;
    for (int i = 0; i < len; ) {
        if (tex[i] >= '0' && tex[i] <= '9') {
            int num = 0;
            while (i < len && tex[i] >= '0' && tex[i] <= '9') {
                num = num*10+tex[i]-'0';
                i++;
            }
            //printf("i:%d num:%d\n", i, num);
            if (mflag == 1) {
                num = -num;
                post[pcnt] = num;
                mark[pcnt] = 0;
                pcnt++;
            } else {
                post[pcnt] = num;
                mark[pcnt] = 0;
                pcnt++;
            }
            
        } else if (tex[i] == '-') {
            if (i == 0 || tex[i-1] < '0' || tex[i-1] > '9') {
                mflag = 1;
                i++;
                continue;
            } else {
                while (top >= 0 && s[top] != '(') {
                    //printf("h\n");
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                //printf("top:%d\n", top);
                s[++top] = tex[i];
            }
            i++;
        } else {
            if (tex[i] == '+') {
                while (top >= 0 && s[top] != '(') {
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                s[++top] = tex[i];
            } else if (tex[i] == '*') {
                while (top >= 0 && (s[top] == '*' || s[top] == '/' || s[top] == '%')) {
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                s[++top] = tex[i];
            } else if (tex[i] == '/') {
                while (top >= 0 && (s[top] == '*' || s[top] == '/' || s[top] == '%')) {
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                s[++top] = tex[i];
            } else if (tex[i] == '%') {
                while (top >= 0 && (s[top] == '*' || s[top] == '/' || s[top] == '%')) {
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                s[++top] = tex[i];
            } else if (tex[i] == '(') {
                s[++top] = tex[i];
            } else if (tex[i] == ')') {
                while (top >= 0 && s[top] != '(') {
                    post[pcnt] = (int)s[top];
                    mark[pcnt] = 1;
                    pcnt++;
                    top--;
                }
                top--;
            }
            /*printf("stack:");
            for (int j = 0; j <= top; j++) printf("%c ", s[j]);
            printf("\n");*/
            i++;
        }
        /*printf("stack:");
        for (int j = 0; j <= top; j++) printf("%c", s[j]);
        printf("\n");*/

        mflag = 0;
    }
    while (top >= 0) {
        post[pcnt] = (int)s[top];
        mark[pcnt] = 1;
        pcnt++;
        top--;
    }

    /*for (int i = 0; i < pcnt; i++) {
        if (mark[i] == 0) printf("%d ", post[i]);
        else printf("%c ", (char)post[i]);
    }
    printf("\n");*/

    for (int i = 0; i < pcnt; i++) {
        if (mark[i] == 0) {
            cal[++ctop] = post[i];
        } else if (mark[i] == 1) {
            char op = (char)post[i];
            int a2 = cal[ctop--];
            int a1 = cal[ctop--];
            if (op == '+') {
                cal[++ctop] = a1+a2;
            } else if (op == '-') {
                cal[++ctop] = a1-a2;
            } else if (op == '*') {
                cal[++ctop] = a1*a2;
            } else if (op == '/') {
                cal[++ctop] = a1/a2;
            } else if (op == '%') { 
                cal[++ctop] = a1%a2;
            }
        }
        /*for (int j = 0; j <= ctop; j++) printf("%d ", cal[j]);
        printf("\n");*/
    }
    printf("%d\n", cal[ctop]);
    
    return 0;
}
