class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # 利用二进制每一位是否为1来进行枚举即可
        n = len(nums)
        rtn = []
        for i in range(2**n):
            tmp = []
            cur = i
            for j in range(n):
                if cur & 1 == 1: 
                    tmp.append(nums[j])
                cur = cur >> 1
            rtn.append(tmp)
        
        return rtn