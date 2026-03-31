class Solution:
    def binarySearchInLeft(self, target: int, mountainArr: 'MountainArray', l: int, r: int) -> int:
        while l <= r:
            mid = l + (r-l)//2
            val = mountainArr.get(mid)
            if val == target:
                return mid
            elif target < val:
                r = mid - 1
            else:
                l = mid + 1
        return -1

    def binarySearchInRight(self, target: int, mountainArr: 'MountainArray', l: int, r: int) -> int:
        while l <= r:
            mid = l + (r-l)//2
            val = mountainArr.get(mid)
            if val == target:
                return mid
            elif target > val:
                r = mid - 1
            else:
                l = mid + 1
        return -1

    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        l, r = 0, mountainArr.length()-1
        index = 0
        while l < r:
            mid = l + (r-l)//2
            left, right = mountainArr.get(mid - 1), mountainArr.get(mid + 1)
            middle = mountainArr.get(mid)

            if left < middle > right:
                index = mid
                break
            elif left < middle:
                l = mid
            else:
                r = mid
        
        if mountainArr.get(index) == target:
            return index
        
        res = self.binarySearchInLeft(target, mountainArr, 0, index - 1)
        if res == -1:
            res = self.binarySearchInRight(target, mountainArr, index + 1, mountainArr.length()-1)\
        
        return res