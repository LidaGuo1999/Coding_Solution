''' 输入一行表示该一元一次方程，其中未知数为X，方程包含加法、减法、乘法。

字符串长度少于20个字符，保证为合法方程。

所有整数绝对值不超过10000000。
'''

def term_split(s):
    co = []
    terms = []
    i = 0
    while i < len(s):
        if s[i] == '+':
            co.append(1)
        elif s[i] == '-':
            co.append(-1)
        else:
            co.append(1)
            i -= 1
        term = ''
        for j in range(i+1, len(s)):
            if s[j] != '+' and s[j] != '-':
                term += s[j]
                if j == len(s)-1:
                    i = j+1
                    break
            else:
                i = j
                break
        terms.append(term)

    return co, terms

def term_cal(s):
    


if __name__ == '__main__':
    equation = input().strip()
    left, right = equation.split('=')
    co_left, terms_left = term_split(left)
    co_right, terms_right = term_split(right)
    cons_left, cons_right, coe_left, coe_right = 0
    for i in range(len(co_left)):

