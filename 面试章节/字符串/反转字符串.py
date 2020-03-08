from typing import List
# 思想很简单，设置双指针，i从头开始，j从尾部开始，利用一个临时变量temp交换二者的元素，然后双向遍历即可
# 52ms, 96.71%; 14.6MB, 100%
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i = 0
        j = len(s)-1
        exchange = None
        while i < j:
            temp = s[j]
            s[j] = s[i]
            s[i] = temp
            i += 1
            j -= 1
        return s