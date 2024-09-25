class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<unordered_map<char, int>> groupCounts; // character frequency for each group i

        for (string & str : strs) {
            // Get character frequencies of this string
            unordered_map<char, int> strCounts;
            for (char c : str)
                strCounts[c] += 1;

            // Check if it's the same as an existing group
            bool found = false;
            for (int i=0; i<groupCounts.size(); ++i) {
                if (groupCounts[i] == strCounts) {
                    ans[i].push_back(str);
                    found = true;
                }
            }

            if (!found) {
                ans.push_back({str});
                groupCounts.push_back(strCounts);
            }
        }

        return ans;
    }
};