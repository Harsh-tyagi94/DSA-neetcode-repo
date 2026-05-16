class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        target, window = [0]*26, [0]*26
        size = len(s1)
        for ch in s1:
            target[ord(ch)-97] += 1
        
        prev = 0
        for i, ch in enumerate(s2):
            window[ord(ch)-97] += 1
            if target[ord(ch)-97] == 0:
                while prev <= i:
                    window[ord(s2[prev])-97] -= 1
                    prev += 1

            if size == i - prev + 1:
                if target == window:
                    return True
                window[ord(s2[prev])-97] -= 1
                prev += 1

        return False

"""
target = {
    a: 1, b: 0, c:1, d: 1
}
window = {
    d: 0,
    a: 1,
}
prev = 1
"""