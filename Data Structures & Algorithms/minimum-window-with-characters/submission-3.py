class Solution:
    def minWindow(self, s: str, t: str) -> str:
        target, window = {}, {}
        for ch in t:
            target[ch] = 1 + target.get(ch, 0)
        
        need, have = len(target), 0
        res = (-1, float('inf'))
        prev = 0

        for i in range(len(s)):
            window[s[i]] = 1 + window.get(s[i], 0)
            if s[i] in target and window[s[i]] == target[s[i]]:
                have += 1
            
            while have == need:
                if res[1] > i - prev + 1:
                    res = (prev, i-prev+1)
                window[s[prev]] -= 1
                if s[prev] in target and window[s[prev]] < target[s[prev]]:
                    have -= 1
                prev += 1

        return s[res[0]:res[0]+res[1]] if res[0] != -1 else ""