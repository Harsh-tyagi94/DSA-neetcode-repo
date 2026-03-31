class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}

        for i,key in enumerate(strs):
            key = ''.join(sorted(key))
            if key not in mp:
                mp[key] = []
            mp[key].append(strs[i])
        
        res = []

        for key,l in mp.items():
            a = []
            for s in l:
                a.append(s)
            
            res.append(a)

        return res
        