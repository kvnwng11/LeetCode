class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = {}
        for f, t, price in flights:
            if f not in adj:
                adj[f] = []
                
            adj[f].append((t, price))
        
        dists = [math.inf] * n
        
        # BFS
        q = deque()
        q.append((src, 0)) # (node, dist)
        
        stops = 0
        
        while stops <= k and q:
            size = len(q)
            
            for i in range(size):
                node, dist = q.popleft()
                
                if node not in adj:
                    continue
                    
                for neighbor, price in adj[node]:
                    if price + dist < dists[neighbor]:
                        dists[neighbor] = price + dist
                        q.append((neighbor, price + dist))
            
            stops += 1
        
        return -1 if dists[dst] == math.inf else dists[dst]
        