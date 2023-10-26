class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Get start and ends
        unordered_map<char, int> ends;
        for (int i=0; i<s.size(); ++i) {
            ends[s[i]] = i;
        }

        vector<int> ans;
        int endOfSegment = ends[s[0]];
        int left = 0;
        for (int i=0; i<s.size(); ++i) {
            endOfSegment = max(endOfSegment, ends[s[i]]);

            if (i == endOfSegment) {
                ans.push_back(i - left + 1);
                left = i + 1;
            }
        }

        return ans;
    }
};