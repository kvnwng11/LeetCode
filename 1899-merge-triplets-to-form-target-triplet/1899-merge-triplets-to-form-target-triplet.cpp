class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool canForm[3] = { false };
        int aTarget = target[0], bTarget = target[1], cTarget = target[2];

        for (auto &triplet : triplets) {
            int a = triplet[0], b = triplet[1], c = triplet[2];

            if (a == aTarget) {
                canForm[0] |= b <= bTarget && c <= cTarget;
            }
            if (b == bTarget) {
                canForm[1] |= a <= aTarget && c <= cTarget;
            }
            if (c == cTarget) {
                canForm[2] |= a <= aTarget && b <= bTarget;
            }
        }
        
        return canForm[0] && canForm[1] && canForm[2];
    }
};