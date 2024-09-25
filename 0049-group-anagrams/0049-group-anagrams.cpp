class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string &str : strs) {
            // Get character frequencies of this string
            int counts[26] = {};
            for (char c : str)
                counts[c - 'a']++;

            // Serialize
            string key = "";
            for (int i=0; i<26; ++i) {
                key += '#';
                key += to_string(counts[i]);
            }

            if (!ans.count(key)) ans[key] = vector<string>();
            ans[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto &[key, group] : ans) {
            res.push_back(group);
        }

        return res;
    }
};