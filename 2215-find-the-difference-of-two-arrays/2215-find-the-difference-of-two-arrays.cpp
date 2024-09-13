class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> present1;
        unordered_set<int> present2;

        for (int num : nums1)
            present1.insert(num);
        for (int num : nums2)
            present2.insert(num);

        vector<vector<int>> ans(2, vector<int>(0));

        for (int num : present1)
            if (present2.count(num) == 0)
                ans[0].push_back(num);
        for (int num : present2)
            if (present1.count(num) == 0)
                ans[1].push_back(num);
        
        return ans;
    } 
};