class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = [0]*26
        for pt in s:
            count[ord(pt)-ord('a')] += 1
        
        for pt in t:
            if count[ord(pt)-ord('a')] == 0:
                return False
            count[ord(pt)-ord('a')] -= 1


        return True