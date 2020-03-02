from typing import List
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        remain = [x for x in votes[0]]
        length = len(votes[0])
        rank = []
        for i in range(length):
            rank.append({})
        for v in votes:
            for i in range(length):
                if v[i] in rank[i]:
                    rank[i][v[i]] += 1
                else:
                    rank[i][v[i]] = 1
        print(rank)

if __name__ == "__main__":
    solution = Solution()
    votes = ["ABC","ACB","ABC","ACB","ACB"]
    solution.rankTeams(votes)
