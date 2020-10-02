#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int heap[1000], tail;

void insert(int num);
void pop();

int main() {
    int n, tmp;
    printf("Number of heap:");
    scanf("%d", &n);
    printf("Please input all the numbers below.\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        insert(tmp);
    }
    
    printf("top:%d\n", heap[1]);
    pop();
    printf("top:%d\n", heap[1]);
    printf("Insert a new value:\n");
    scanf("%d", &tmp);
    insert(tmp);
    printf("top:%d\n", heap[1]);
}

void insert(int num) {
    if (tail == 0) {
        tail++;
        heap[tail] = num;
        return ;
    }
    
    heap[++tail] = num;
    int pos = tail;
    while (pos > 1) {
        if (heap[pos] < heap[pos/2]) {
            int tmp = heap[pos];
            heap[pos] = heap[pos/2];
            heap[pos/2] = tmp;
            pos /= 2;
            continue;
        } else {
            break;
        }
    }
    return ;
}

void pop() {
    if (tail == 0) {
        printf("No element in the heap!\n");
        return ;
    }
    heap[1] = heap[tail];
    tail--;
    int pos = 1;
    while (pos*2 <= tail) {
        //printf("pos:%d\n", pos);
        int left = heap[pos*2], right = INT_MAX;
        if (pos*2+1 <= tail) right = heap[pos*2+1];

        if (heap[pos] > left && left < right) {
            int tmp = left;
            heap[pos*2] = heap[pos];
            heap[pos] = tmp;
            pos *= 2;
        } else if (heap[pos] > right && right < left) {
            int tmp = right;
            heap[pos*2+1] = heap[pos];
            heap[pos] = tmp;
            pos = pos*2+1;
        } else {
            break;
        }
    }
    return ;
}
