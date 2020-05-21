

if __name__ == '__main__':
    n, m = list(map(int, input().strip().split()))
    candy = list(map(int, input().strip().split()))
    cost = [1] * n
    combine = []
    k = int(input().strip())
    for q in range(k):
        i, j = list(map(int, input().strip().split()))
        candy[i-1] += candy[j-1]
        cost[i-1] += 1
        combine.append(j-1)
    new_candy = []
    new_cost = []
    for i in range(n):
        if i not in combine:
            new_candy.append(candy[i])
            new_cost.append(cost[i])

    dp = []
    nn = len(new_candy)
    print(new_candy)
    print(new_cost)
    for i in range(nn):
        dp.append([0] * m)
    for i in range(m):
        if new_candy[0] <= (i+1):
            dp[0][i] = new_cost[0]
        else:
            dp[0][i] = 0

    print(dp)

    for i in range(1, nn):
        for j in range(m):
            if j == 0:
                dp[i][j] = dp[i-1][j]
                continue
            if new_candy[i] > (j+1):
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-new_candy[i]]+new_cost[i])

    print(dp)
    print(dp[-1][-1])
