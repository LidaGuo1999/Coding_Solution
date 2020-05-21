

if __name__ == '__main__':
    T = int(input().strip())
    for t in range(T):
        n, m = list(map(int, input().strip().split()))
        fruit = list(map(int, input().strip().split()))
        min_count = sum(fruit) // m
        flag = 0
        for i in range(min_count, 0, -1):
            count = 0
            for j in range(n):
                count += fruit[j] // i
            if count >= m:
                print(i)
                flag = 1
                break
        if flag == 0:
            print(0)


