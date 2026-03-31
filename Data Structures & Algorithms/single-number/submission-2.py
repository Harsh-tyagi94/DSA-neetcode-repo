class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums_xor = nums[0]

        for i in range(1,len(nums)):
            nums_xor ^= nums[i]
        
        return nums_xor