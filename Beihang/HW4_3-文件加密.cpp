#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    char c;
    struct node *next;
} node;

void init(char key[], char pword[]) {
    int appear[140] = {0};
    node *nhead = (node*)calloc(1, sizeof(node)), *tail = nhead;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        if (appear[key[i]] == 0) {
            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->c = key[i];
            tail->next = tmp;
            tail = tail->next;
            appear[key[i]] = 1;
        } else {
            continue;
        }
    }
    for (int i = 32; i <= 126; i++) {
        if (appear[i] == 0) {
            node *tmp = (node*)calloc(1, sizeof(node));
            tmp->c = (char)i;
            tail->next = tmp;
            tail = tail->next;
            appear[i] = 1;
        } else {
            continue;
        }
    }
    tail->next = nhead->next;
    node *cur = nhead->next, *pre = tail;
    char start = nhead->next->c;
    
    while (cur->next != cur) {
        char s = cur->c;
        pre->next = cur->next, cur = cur->next;
        for (int i = 1; i < (int)s; i++) {
            pre = cur;
            cur = cur->next;
        }
        char e = cur->c;
        pword[s] = e;
    }
    pword[cur->c] = start;

    return ;
}

int main() {
    FILE *in = fopen("in.txt", "r"), *out = fopen("in_crpyt.txt", "w");
    char key[40] = {0}, pword[130] = {0};
    gets(key);
    
    init(key, pword);
    char cur = 0;
    while ((cur = fgetc(in)) != EOF) {
        if (cur >= 32 && cur <= 126) fputc(pword[cur], out);
        else fputc(cur, out);
    }

    fclose(in), fclose(out);
    return 0;
}
