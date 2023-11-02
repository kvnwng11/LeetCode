class Solution {
private:
    int getMaxUnique(string &s) {
        bool map[26] = {0};
        int numUnique = 0;
        for (char c : s) {
            if (!map[c - 'a']) {
                numUnique++;
                map[c-'a'] = 1;
            }
        }
        return numUnique;
    }

public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxUnique = getMaxUnique(s);
        int ans = 0;

        for (int currUnique=1; currUnique <= maxUnique; ++currUnique) {

            int left = 0;
            unordered_map<char, int> counts;
            unordered_set<char> unique;

            // Sliding window
            for (int right = 0; right < s.size(); ++right) {
                char c = s[right];

                unique.insert(c);
                counts[c] += 1;

                // Check if constraint is met
                if (unique.size() == currUnique) {
                    bool found = true;
                    for (char u : unique)  {
                        if (counts[u] < k) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        ans = max(ans, right - left + 1);
                    }
                }

                // Contract
                while (unique.size() > currUnique) {
                    char toRemove = s[left++];
                    counts[toRemove] -= 1;

                    if (counts[toRemove] == 0)
                        unique.erase(toRemove);
                }
            }

        }

        return ans;
    }
};