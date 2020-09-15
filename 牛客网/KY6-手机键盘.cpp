/* 问题描述：按照手机键盘输入字母的方式，计算所花费的时间 如：a,b,c都在“1”键上，输入a只需要按一次，输入c需要连续按三次。 如果连续两个字符不在同一个按键上，则可直接按，如：ad需要按两下，kz需要按6下 如果连续两字符在同一个按键上，则两个按键之间需要等一段时间，如ac，在按了a之后，需要等一会儿才能按c。 现在假设每按一次需要花费一个时间段，等待时间需要花费两个时间段。 现在给出一串字符，需要计算出它所需要花费的时间。
 *
 * 输入描述：一个长度不大于100的字符串，其中只有手机按键上有的小写字母
 *
 * 输出描述：输入可能包括多组数据，对于每组数据，输出按出Input所给字符串所需要的时间
 */

#include <iostream>

using namespace std;

void init(int pos[30]) {
    for (int i = 0; i < 5; i++) {
        pos[i*3+0] = (i+2)*10+1;
        pos[i*3+1] = (i+2)*10+2;
        pos[i*3+2] = (i+2)*10+3;
    }
    for (int i = 0; i < 4; i++) {
        pos[15+i] = 70+i+1;
    }
    for (int i = 0; i < 3; i++) {
        pos[19+i] = 80+i+1;
    }
    for (int i = 0; i < 4; i++) {
        pos[22+i] = 90+i+1;
    }
    return ;
}

int cal(char ar[105], int pos[30]) {
    //for (int i = 0; i < 30; i++) printf("%d ", pos[i]);
    int button = 1, cnt = 0;
    for (int i = 0; ar[i] != 0; i++) {
        //printf("%d\n", pos[ar[i]-'a']);
        if (pos[ar[i]-'a']/10 == button) cnt += 2;
        cnt += pos[ar[i]-'a']%10;
        button = pos[ar[i]-'a']/10;
    }
    return cnt;
}

int main() {
    int pos[30] = {0};
    char ar[105] = {0};
    init(pos);

    while (scanf("%s", ar) != EOF) {
        int ans = cal(ar, pos);
        printf("%d\n", ans);
    }
    
    return 0;
}
