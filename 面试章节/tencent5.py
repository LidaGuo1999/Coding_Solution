import sys

def perfect(x, y, k):
    sum = x[0] + y[0]
    for i in range(1, k):
        if x[i] + y[i] != sum:
            return 0
    return 1

if __name__ == "__main__":
    # 读取第一行的n
    first = sys.stdin.readline().strip().split()
    n = int(first[0])
    k = int(first[1])
    ob = []
    ans = 0
    for i in range(n):
        line = list(map(int, sys.stdin.readline().strip().split()))
        ob.append(line)
    for i in range(n):
        for j in range(i+1, n):
            ans += perfect(ob[i], ob[j], k)
    print(ans)

