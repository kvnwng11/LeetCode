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
    vector<int> sorted;

    void solve(TreeNode* curr) {
        if (!curr) return;

        solve(curr->left);
        sorted.push_back(curr->val);
        solve(curr->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        return sorted[k-1];
    }
};