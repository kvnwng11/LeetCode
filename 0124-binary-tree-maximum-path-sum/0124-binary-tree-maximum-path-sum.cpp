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
    int ans = INT_MIN;

    int gainFromSubtree(TreeNode* root) {
        if (!root) return 0;

        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        int gainFromRight = max(gainFromSubtree(root->right), 0);

        ans = max(ans, gainFromLeft + gainFromRight + root->val);

        return max(gainFromLeft, gainFromRight) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        gainFromSubtree(root);
        return ans;
    }
};