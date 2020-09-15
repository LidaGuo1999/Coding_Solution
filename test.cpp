#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val1;
    int val2;
};

int main() {
    vector<int> i1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<node> i2;
    int a1[10] = {1,1,1,1,1,1,1,1,1,1};
    for (int i = 0; i < 1; i++) {
        node tmp;
        tmp.val1 = 1;
        tmp.val2 = 2;
        i2.push_back(tmp);
    }

    printf("size of i1: %d\n", sizeof(i1));
    printf("size of i2: %d\n", sizeof(i2));
    printf("size of a1: %d\n", sizeof(a1));
    printf("%d\n", i2.size());

    printf("capacity of i2: %d\n", i2.capacity());
    return 0;
}
