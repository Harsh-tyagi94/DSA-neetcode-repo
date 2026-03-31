class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        self.Stack = [(float('inf'),-1)]

        for t,temp in enumerate(temperatures):
            temperatures[t] = 0

            while self.Stack[-1][0] < temp:
               value, key = self.Stack.pop()
               temperatures[key] = t - key

            self.Stack.append((temp,t))

        return temperatures 