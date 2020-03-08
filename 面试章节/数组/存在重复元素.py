# 思路很简单，用一个集合就可以了，判断是否出现过，如果出现过，直接返回即可
# 48ms, 91.73%; 19.3MB, 9.91%
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        appeared = set()
        for i in nums:
            if i in appeared:
                return True
            else:
                appeared.add(i)
        return False