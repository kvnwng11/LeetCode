class Solution:
    
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def inBounds(x, y, n, m):
            return 0 <= new_x < n and 0 <= new_y < m
    
        n = len(heights)
        m = len(heights[0])
        
        max_diffs = [[math.inf] * m for _ in range(n)] 
        max_diffs[0][0] = 0
        visited = [[False] * m for _ in range(n)]
        queue = [(0, 0, 0)] # difference, x, y
        
        while queue:
            difference, x, y = heapq.heappop(queue)
            visited[x][y] = True
            
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                new_x = x + dx
                new_y = y + dy
                
                if inBounds(new_y, new_y, n, m) and not visited[new_x][new_y]:
                    curr_diff = abs(heights[new_x][new_y] - heights[x][y])
                    max_diff = max(curr_diff, max_diffs[x][y])
                    
                    if max_diffs[new_x][new_y] > max_diff:
                        max_diffs[new_x][new_y] = max_diff
                        heapq.heappush(queue, (max_diff, new_x, new_y))
                        
        return max_diffs[-1][-1]