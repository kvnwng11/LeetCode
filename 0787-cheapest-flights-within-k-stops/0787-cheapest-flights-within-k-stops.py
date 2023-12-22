class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        dists = [math.inf] * n
        dists[src] = 0
        
        for i in range(k+1):
            temp = dists.copy()
            
            for f, t, price in flights:
                if dists[f] != math.inf:
                    temp[t] = min(temp[t], dists[f] + price)
                    
            dists = temp.copy()
        
        return -1 if dists[dst] == math.inf else dists[dst]
        