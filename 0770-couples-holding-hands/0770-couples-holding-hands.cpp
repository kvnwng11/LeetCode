class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;

        unordered_map<int, int> idx;
        for (int i=0; i<row.size(); ++i) {
            idx[row[i]] = i;
        }

        for (int i=0; i<row.size(); i += 2) {
            int x = row[i];
            int partner = x % 2 == 0? x+1 : x-1;

            if (row[i+1] == partner) continue;

            ans++;

            int j = idx[partner];
            if (j > i) {
                row[j] = row[i+1];
                row[i+1] = partner;

                idx[partner] = i+1;
                idx[row[j]] = j;
            }
        }

        return ans;
    }
};