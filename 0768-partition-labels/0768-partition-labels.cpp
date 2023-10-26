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
        int count = 0;
        for (int i=0; i<s.size(); ++i) {
            if (i > endOfSegment) {
                ans.push_back(count);
                endOfSegment = ends[s[i]];
                count = 1;
            }
            else {
                count++;
                endOfSegment = max(endOfSegment, ends[s[i]]);
            }
        }
        ans.push_back(count);

        return ans;
    }
};