class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num_to_count;
        unordered_set<int> counts;

        for (int num : arr)
            num_to_count[num] += 1;
        
        for (auto &[num, count] : num_to_count) {
            if (counts.find(count) != counts.end())
                return false;
            else
                counts.insert(count);
        }
        return true;
    }
};