class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;

        for (int i=0; i<row.size(); i += 2) {
            int x = row[i];
            int partner = x % 2 == 0? x+1 : x-1;

            if (row[i+1] == partner) continue;

            ans++;

            for (int j=i+1; j<row.size(); ++j) {
                if (row[j] == partner) {
                    row[j] = row[i+1];
                    row[i+1] = partner;
                }
            }
        }

        return ans;
    }
};