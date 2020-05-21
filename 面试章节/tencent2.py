import sys
if __name__ == "__main__":
    # 读取第一行的n
    first = sys.stdin.readline().strip().split()
    n = int(first[0])
    g = int(first[1])
    ans = 0
    cost_sum = 0
    cost = []
    profit = []
    for i in range(n):
        # 读取每一行
        line = sys.stdin.readline().strip()
        # 把每一行的数字分隔后转化成int列表
        c, w = list(map(int, line.split()))
        cost.append(c)
        profit.append(w - (float)c/2)
    for i in range(n):
        for j in range(i+1, n):
            if profit[i] < profit[j]:
                tmp = profit[i]
                profit[i] = profit[j]
                profit[j] = tmp
                tmp = cost[i]
                cost[i] = cost[j]
                cost[j] = tmp
    for i in range(n):
        if profit[i] > 0:
            print(profit[i])
            ans += profit[i] 
            cost_sum += cost[i]
    if cost_sum % g != 0:
        
    ans = int(ans)
    print(ans)
