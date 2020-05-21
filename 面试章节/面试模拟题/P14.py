

if __name__ == '__main__':
    s = input().strip()
    once = set()
    ans = ''
    for i in range(len(s)):
        if s[i] not in once:
            once.add(s[i])
            ans += s[i]
    print(ans)