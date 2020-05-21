

if __name__ == '__main__':
    n = int(input().strip())
    stone = list(map(int, input().strip().split()))

    while len(stone) > 1:
        tmp = []
        stone.sort(reverse=True)
        print(stone)
        for i in range(len(stone) // 2):
            if stone[2*i+1]-stone[2*i] < 0:
                tmp.append(stone[2*i]-stone[2*i+1])
        if len(stone) % 2 == 1:
            tmp.append(stone[-1])
        stone = []
        for i in range(len(tmp)):
            stone.append(tmp[i])

    if len(stone) == 0:
        print(0)
    elif len(stone) == 1:
        print(stone[0])
    else:
        print('something wrong.')