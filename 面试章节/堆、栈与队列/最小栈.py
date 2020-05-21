# 该题主要是为了实现一个简单的栈。这个栈的特别点在于它需要能够在常数时间内取到最小值，所以我们用另一个数组将当前最小值储存起来即可。
# 80ms, 51.34%; 16.8MB, 6.60%
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.t = -1
        self.end = -1
        self.minValue = []


    def push(self, x: int) -> None:
        self.t += 1
        if self.end >= self.t:
            self.stack[self.t] = x
        else:
            self.end += 1
            self.stack.append(x)
            self.minValue.append(0)
            
        if self.t == 0:
            self.minValue[self.t] = x
        elif x < self.minValue[self.t-1]:
            self.minValue[self.t] = x
        else:
            self.minValue[self.t] = self.minValue[self.t-1]


    def pop(self) -> None:
        self.t -= 1


    def top(self) -> int:
        return self.stack[self.t]


    def getMin(self) -> int:
        return self.minValue[self.t]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()