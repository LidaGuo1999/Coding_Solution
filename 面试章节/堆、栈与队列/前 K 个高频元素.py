# 首先利用字典统计出每个元素的频次，然后再利用桶排序的方法按照频次排序即可。
# 124ms, 70.94%; 18MB, 0%
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        fre = {}
        ans = []
        for n in nums:
            if fre.get(n) == None:
                fre.setdefault(n, 1)
            else:
                fre[n] += 1
        bucket = []
        for i in range(max(fre.values()) + 1):
            bucket.append(list())
        for j in fre.keys():
            bucket[fre[j]].append(j)
        cnt = 0
        for i in reversed(range(len(bucket))):
            for j in bucket[i]:
                if cnt < k:
                    ans.append(j)
                    cnt += 1
        return ans