class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        results = []
        def sum_util(target, curr_idx, result):
            if target == 0:
                results.append(result)
                return
            if target < 0:
                return
            for i in range(curr_idx, len(candidates)):
                if i != curr_idx and candidates[i] == candidates[i - 1]:
                    continue
                sum_util(target - candidates[i], i + 1, result + [candidates[i]])
        candidates.sort()
        sum_util(target, 0, [])
        return results
    
if __name__ == '__main__':
    candidates = list(map(int, input().strip().split()))
    target = int(input())
    print(Solution().combinationSum2(candidates, target))