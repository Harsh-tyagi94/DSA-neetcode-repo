class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        Stack = [(-1, 0)]
        res = 0
        for i, num in enumerate(heights):
            temp = i
            while Stack[-1][0] >= num:
                height, index = Stack.pop()
                res = max(res, height*(i-index))
                temp = index
            
            Stack.append((num, temp))
        
        n = len(heights)
        while len(Stack) > 1:
            height, index = Stack.pop()
            res = max(res, height*(n-index))
        
        return res
