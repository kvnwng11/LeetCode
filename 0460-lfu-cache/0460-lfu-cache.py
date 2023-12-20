class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {} # key -> [value, count]
        self.cache_counts = {} # key -> OrderedDict(key -> None)
        self.min_count = 0

    def get(self, key: int) -> int:
        # Not in cache
        if key not in self.cache:
            return -1
        
        # Update count
        value, old_count = self.cache[key]
        self.cache[key][1] += 1
        self.cache_counts[old_count].pop(key)
        self.update_counts(key, old_count + 1)
        
        # Update min_count
        if old_count == self.min_count and len(self.cache_counts[old_count]) == 0:
            self.min_count += 1
        
        return value

    def put(self, key: int, value: int) -> None:
        # Key exists
        if key in self.cache:
            _ = self.get(key)
            self.cache[key][0] = value
            return
        
        # Make room
        if len(self.cache) == self.capacity:
            to_remove, _ = self.cache_counts[self.min_count].popitem(False)
            self.cache.pop(to_remove)
            
        # Put into cache
        self.cache[key] = [value, 1]
        self.update_counts(key, 1)
        self.min_count = 1
    
    def update_counts(self, key: int, count: int):
        if count not in self.cache_counts:
            self.cache_counts[count] = collections.OrderedDict()
            
        self.cache_counts[count][key] = None

# Cache object will be instantiated and called as such:
# obj = LFU
# Your LFUCCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)