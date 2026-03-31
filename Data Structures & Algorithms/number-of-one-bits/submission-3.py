class Solution:
    def hammingWeight(self, n: int) -> int:
        count_set_bits = 0

        while n != 0:
            if n & 1:
                count_set_bits += 1
            
            n = n >> 1
        return count_set_bits 