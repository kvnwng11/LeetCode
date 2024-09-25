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

public:
    bool isValidBST(TreeNode* root) {
       // check max value of left subtree
       // check min value of right subtree

        if (!root) return true;

        long maxLeft = LONG_MIN;
        long minRight = LONG_MAX;

        // Find min value in right subtree
        TreeNode* right = root->right;
        while (right && right->left)
            right = right->left;
        if (right)
            minRight = right->val;

        // Find max value in left subtree
        TreeNode* left = root->left;
        while (left && left->right)
            left = left->right;
        if (left)
            maxLeft = left->val;

        if (maxLeft >= root->val || root->val >= minRight) return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};