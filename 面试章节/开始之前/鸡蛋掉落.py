class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        top = N+1
        count = 0
        if K == 1:
            return N
        while K > 1 and top > 5:
            top = top // 2
            count += 1
            K -= 1
        if top > 5:
            count += (top - 1)
        elif top == 5 and K >= 2:
            count += 3
        elif top == 5 and K == 1:
            count += 4
        elif top == 4 and K >= 2:
            count += 2
        elif top == 4 and K == 1:
            count += 3
        elif top <= 3 and K >= 1:
            count += top - 1
        return count
        

if __name__ == "__main__":
    solution = Solution()
    print(solution.superEggDrop(3, 14))