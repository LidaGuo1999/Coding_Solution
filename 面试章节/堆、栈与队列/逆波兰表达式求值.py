# 本题就是简单的逆波兰表达式求值，是基础知识，主要用栈完成。
# 48ms, 78.89%; 13.8MB, 0%
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        top = -1
        oper = ['+', '-', '*', '/']
        for i in tokens:
            if i not in oper:
                top += 1
                if len(stack) <= top:
                    stack.append(int(i))
                else:
                    stack[top] = int(i)
            else:
                right = stack[top]
                top -= 1
                left = stack[top]
                top -= 1
                if i == '+':
                    top += 1
                    stack[top] = left + right
                elif i == '-':
                    top += 1
                    stack[top] = left - right
                elif i == '*':
                    top += 1
                    stack[top] = left * right
                elif i == '/':
                    top += 1
                    stack[top] = int(left / right)
        if top != 0:
            print('something wrong!')
        return stack[0]