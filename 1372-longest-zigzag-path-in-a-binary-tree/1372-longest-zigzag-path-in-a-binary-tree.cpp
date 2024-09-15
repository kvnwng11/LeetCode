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
    int ans = 0;

    void solve(TreeNode* curr, bool isRightChild, int length) {
        if (!curr) return;

        ans = max(ans, length);
        
        if (isRightChild) {
            solve(curr->left, false, length+1);
            solve(curr->right, true, 1);
        }
        else {
            solve(curr->right, true, length+1);
            solve(curr->left, false, 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        solve(root, false, 0);
        solve(root, true, 0);
        return ans;
    }
};