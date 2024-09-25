/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    const int MOD_1 = 10e7 + 7;
    const int MOD_2 = INT_MAX;

    vector<pair<unsigned long long, unsigned long long>> memo;

    pair<unsigned long long, unsigned long long> hashTree(TreeNode* node, bool needToAdd) {
        if (node == nullptr) return {3, 7};

        auto left = hashTree(node->left, needToAdd);
        auto right = hashTree(node->right, needToAdd);

        auto left1 = (left.first << 5) % MOD_1;
        auto right1 = (right.first << 1) % MOD_1;
        auto left2 = (left.second << 7) % MOD_2;
        auto right2 = (right.second << 1) % MOD_2;

        pair hashpair = {(left1 + right1 + node->val) % MOD_1, (left2 + right2 + node->val) % MOD_2};
        if (needToAdd) memo.push_back(hashpair);
        return hashpair;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        hashTree(root, true);

        auto s = hashTree(subRoot, false);

        return find(memo.begin(), memo.end(), s) != memo.end();
    }
};