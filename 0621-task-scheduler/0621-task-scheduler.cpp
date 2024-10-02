class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        int biggest = 0;
        for (char c : tasks) {
            counts[c] += 1;
            biggest = max(biggest, counts[c]);
        }
        int ans = (biggest-1) * (n+1);
        for (auto &[c, freq] : counts)
            if (freq == biggest)
                ans++;

        return max((int) tasks.size(), ans);
    }
};