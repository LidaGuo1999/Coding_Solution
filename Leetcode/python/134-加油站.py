class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # 我们注意到，如果从x能够到的最远距离为y，那么区间[x,y]中的任何一点都不能到y+1，因此我们只需要从加油站0开始看能不能走一圈，如果在y处不能继续，那么选取y+1作为起始点看能不能走一圈。如果出发点回到了原点（或者出发点已经绕了一圈），那么说明肯定不能完成。因此实际上只需要单次遍历即可。
        start = 0
        n = len(cost)
        flag = 0
        while start < n:
            remain = 0
            cur = start
            while True:
                print(start, cur)
                remain += gas[cur]-cost[cur]
                print(remain)
                if remain < 0:
                    if (cur+1)%n <= start: return -1
                    start = cur+1
                    break
                else:
                    cur = (cur+1)%n
                    if cur == start:
                        flag = 1
                        break
            if flag == 1: return start

        return -1