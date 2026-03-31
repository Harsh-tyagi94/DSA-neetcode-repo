class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # uset = set()
        # for num in nums:
        #     if num in uset:
        #         return True
        #     uset.add(num)
        # return False

        nums.sort()
        for i in range(1,len(nums)):
            if nums[i-1] == nums[i]:
                return True
        
        return False
         