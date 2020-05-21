'''
现在你的班级刚刚参加了一个只有单选题的考试。班级一共n个学生，考试有m个问题。每个题目都有5个可选答案（A，B，C，D，E）。并且每个题目只有一个正确答案。每个题目的分数并不一样，第i个题目的分数用a[i]表示。如果题目没答对该题会获得0分。
考试结束后，每个学生都记得自己的答案，但是他们还不知道正确答案是什么。如果非常乐观的考虑，他们班级最多可能得到多少分呢？

输入：
第一行包含2个正整数，n和m。(1 <= n, m <= 1000，n是班级中学生数量，m是题目的数量)

下面n行数据每行包含一个string si，表示第i个学生的答案。si的第j个字符表示该学生第j个题目的答案。

输出：
一个正整数，全班学生最大的可能获得的分数总和。
'''

if __name__ == '__main__':
    n, m = list(map(int, input().strip().split()))
    save = []
    ans = 0

    for i in range(n):
        save.append(input().strip())

    point = list(map(int, input().strip().split()))

    for i in range(m):
        flag = [0] * 5
        for j in range(n):
            if save[j][i] == 'A':
                flag[0] += 1
            elif save[j][i] == 'B':
                flag[1] += 1
            elif save[j][i] == 'C':
                flag[2] += 1
            elif save[j][i] == 'D':
                flag[3] += 1
            else:
                flag[4] += 1
        ans += max(flag)*point[i]

    print(ans)
