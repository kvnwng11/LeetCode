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
    void dfs(TreeNode* node, vector<int> &leaves) {
        if (!node) return;

        if (node->left) dfs(node->left, leaves);
        if (!node->left and !node->right) leaves.push_back(node->val);
        if (node->right) dfs(node->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;

        dfs(root1, leaf1);
        dfs(root2, leaf2);

        return leaf1 == leaf2;
    }
};