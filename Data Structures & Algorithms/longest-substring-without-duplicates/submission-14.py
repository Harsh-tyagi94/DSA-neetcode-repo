class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = {}
        prev, res = 0, 0

        for index, ch in enumerate(s):
            j = ord(ch)
            window[j] = window.get(j, 0) + 1
            if window[ord(ch)] > 1:
                while window[ord(s[prev])] != window[j]:
                    window[ord(s[prev])] -= 1
                    prev += 1
                window[ord(s[prev])] -= 1
                prev += 1
            res = max(res, index-prev+1)
        
        return res