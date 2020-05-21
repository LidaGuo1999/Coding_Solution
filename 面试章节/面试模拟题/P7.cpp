/* 最近月神需要在移动端部署一个卷积神经网络模型,但是月神碰到了一个问题,即月神使用了一个核非常大的最大池化(max-pooling)操作,但现有推理引擎不支持这一操作,作为月神的好朋友,你能帮帮月神么。
所谓max-pooling,指的是给定一个数组（为了简化问题,暂定数组为一维）,在每一个滑动窗口内找出最大的那个数,举例如下：
假设数组为[16, 19, 15, 13, 16, 20],且核大小为3,则当窗口依次滑过数组时,取出如下4个子数组：
[16, 19, 15], [19, 15, 13], [15, 13, 16], [13, 16, 20],这4个子数组中的最大值分别为19, 19, 16, 20,故该数组经过大小为3的核的max-pooling的结果为19 19 16 20.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void max_insert(deque<int> &value, deque<int> &index, int number, int pos);
void check_front(deque<int> &value, deque<int> &index, int head_index);

int main() {
    int n, ks = 0;

    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cin >> ks;

    deque<int> value, index;
    vector<int> ans(n-ks+1);
    for (int i = 0; i < ks; i++) {
        max_insert(value, index, array[i], i);
    }
    ans[0] = value.front();
    for (int i = 1; i < n-ks+1; i++) {
        check_front(value, index, i);
        max_insert(value, index, array[i+ks-1], i+ks-1);
        ans[i] = value.front();
    }
    for (int i = 0; i < n-ks+1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

void max_insert(deque<int> &value, deque<int> &index, int number, int pos) {
    while (!value.empty() && value.back() < number) {
        value.pop_back();
        index.pop_back();
    }
    value.push_back(number);
    index.push_back(pos);
}

void check_front(deque<int> &value, deque<int> &index, int head_index) {
    while (!index.empty() && index.front() < head_index) {
        value.pop_front();
        index.pop_front();
    }
} 



