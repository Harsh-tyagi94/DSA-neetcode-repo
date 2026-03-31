class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}

        for n in nums:
            mp[n] = 1+mp.get(n, 0);
        
        minHeap = []
        for num in mp.keys():
            heapq.heappush(minHeap, (mp[num], num))
            if len(minHeap) > k:
                heapq.heappop(minHeap)

        res = []
        for i in range(k):
            res.append(heapq.heappop(minHeap)[1])
        return res