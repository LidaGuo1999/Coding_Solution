'''
小明最近在做病毒自动检测，他发现，在某些library 的代码段的二进制表示中，如果包含子串并且恰好有k个1，就有可能有潜在的病毒。library的二进制表示可能很大，并且子串可能很多，人工分析不可能，于是他想写个程序来先算算到底有多少个子串满足条件。如果子串内容相同，但是开始或者结束位置不一样，则被认为是不同的子串。
注：子串一定是连续的。例如"010"有6个子串，分别是 "0, "1", "0", "01", "10", "010"

输入：
第一行是一个整数k，表示子串中有k个1就有可能是病毒。其中 0 <= k <= 1 000 000

第二行是一个字符串，就是library的代码部分的二进制表示。字符串长度 <= 1 000 000。并且字符串中只包含"0"或"1".

输出：
输出一个整数，所有满足只包含k个1的子串的个数。
'''

if __name__ == '__main__':
    k = int(input().strip())
    binary = input().strip()
    n = len(binary)
    ans = 0
    increase = 0
    count = [0]
    for i in range(n):
        if binary[i] == '1':
            increase += 1
        count.append(increase)

    for i in range(n):
        for j in range(n-i):
            gap = i+1
            if count[j+gap]-count[j] == k:
                ans += 1

    print(ans)


