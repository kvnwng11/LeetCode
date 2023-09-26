class Solution {
private:
    vector<int> take(vector<int> &nums, int i) {
        vector<int> res;
        int maxPop = nums.size() - i;
        for (int j=0; j<nums.size(); ++j) {
            while (res.size() and res.back() < nums[j] and maxPop) {
                res.pop_back();
                maxPop--;
            }
            res.push_back(nums[j]);
        }

        while (res.size() > i)
            res.pop_back();

        return res;
    }

    string merge(vector<int>& nums1, vector<int>& nums2) {
        string res = "";
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() and p2 < nums2.size()) {
            if (nums1[p1] > nums2[p2]) {
                res += (nums1[p1] + '0');
                p1++;
            }
            else if (nums1[p1] < nums2[p2]){
                res += (nums2[p2] + '0');
                p2++;
            }
            else {
                int i1 = p1, i2 = p2;
                while (i1 < nums1.size() and i2 < nums2.size() and nums1[i1] == nums2[i2]) {
                    i1++; i2++;
                }

                if (i2 == nums2.size()) {
                    res += (nums1[p1] + '0');
                    p1++;
                }
                else if (i1 < nums1.size() and nums1[i1] > nums2[i2]) {
                    res += (nums1[p1] + '0');
                    p1++;
                }
                else {
                    res += (nums2[p2] + '0');
                    p2++;
                }
            }
        }
        while (p1 < nums1.size()) {
            res += (nums1[p1] + '0');
            p1++;
        }
        while (p2 < nums2.size()) {
            res += (nums2[p2] + '0');
            p2++;
        }

        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        string ans = "";

        // Take i from nums1, k-i from nums2
        for (int i=0; i <= nums1.size() and i <= k; ++i) {
            if (k - i > nums2.size()) continue;
            vector<int> n1 = take(nums1, i);
            vector<int> n2 = take(nums2, k-i);
            cout << n1.size() + n2.size() << endl;
            string s = merge(n1, n2);

            cout << s << endl << endl;

            ans = max(ans, s);
        }

        vector<int> res;
        for (int i=0; i<ans.size(); ++i) {
            res.push_back(ans[i] - '0');
        }
        return res;
    }
};