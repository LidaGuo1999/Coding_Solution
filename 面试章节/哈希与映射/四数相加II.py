# 使用字典（哈希表）来存储AB中数字和出现的个数，用CD来与之对比，比较简单
# 460ms, 27.94%; 34.7MB
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        ab = {}
        n = len(A)
        ans = 0
        for i in range(n):
            for j in range(n):
                s = A[i]+B[j]
                if ab.get(s) == None:
                    ab.setdefault(s, 1)
                else:
                    ab[s] += 1
        for i in range(n):
            for j in range(n):
                s = C[i]+D[j]
                if ab.get(-s) != None:
                    ans += ab[-s]
        return ans