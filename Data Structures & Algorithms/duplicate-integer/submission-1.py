class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        uset = set()
        for num in nums:
            if num in uset:
                return True
            uset.add(num)
        return False
         