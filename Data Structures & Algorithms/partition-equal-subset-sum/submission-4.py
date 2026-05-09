class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = 0
        for num in nums:
            target += num
        
        if target%2:
            return False
        target //= 2
        n = len(nums)
        dp = [False]*(target+1)
        dp[0] = True

        for n in nums:
            for t in range(target, n-1, -1):
                dp[t] = dp[t] or dp[t - n]
        return dp[target]
            
