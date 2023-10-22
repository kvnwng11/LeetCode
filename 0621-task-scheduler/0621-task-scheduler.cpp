class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int largest = 0;
        unordered_map<char, int> counts;
        for (char c : tasks) {
            counts[c] += 1;
            largest = max(counts[c], largest);
        }

        int freq = 0;
        for (auto &p : counts) {
            if (p.second == largest)
                freq++;
        }

        return max((int)tasks.size(), (int)((largest - 1) * (n + 1) + freq));
    }
};