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
    int solve(TreeNode* curr, int biggest) {
        if (!curr) return 0;
        int isGood = 0;
        if (curr->val >= biggest) {
            isGood = 1;
            biggest = curr->val;
        }

        return solve(curr->left, biggest) + solve(curr->right, biggest) + isGood;
    }

public:
    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};