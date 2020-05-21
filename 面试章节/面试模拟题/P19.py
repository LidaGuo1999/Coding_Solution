
def cal_A(n):
    ans = 1
    for i in range(1, n+1):
        ans *= i
    return ans

if __name__ == '__main__':
    s = input().strip()
    count = {}
    for letter in s:
        if count.get(letter) != None:
            count[letter] += 1
        else:
            count.setdefault(letter, 1)
    #print(count)

    ans = cal_A(len(s))
    for v in count.values():
        ans = ans // cal_A(v)
    if len(s) == 0:
        print(0)
    else:
        print(ans)