import heapq
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        if start_node == end_node:
            return 1

        adj = [[] for _ in range(n)]

        for i in range(len(edges)):
            adj[edges[i][0]].append([edges[i][1], succProb[i]])
            adj[edges[i][1]].append([edges[i][0], succProb[i]])

        visit = set()
        heap = [(-1, start_node)]
        prob = 0

        while heap:
            cost, node = heapq.heappop(heap)
            cost = -cost

            if node == end_node:
                prob = max(prob, cost)
            
            visit.add(node)
            for neig, edge_prob in adj[node]:
                if neig not in visit:
                    heapq.heappush(heap, (-cost*edge_prob, neig))
        
        return prob