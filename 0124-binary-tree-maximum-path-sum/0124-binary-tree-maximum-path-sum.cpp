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
    
    int solve(TreeNode* node) {
        if (!node) return 0;
        
        int left = max(solve(node->left), 0);
        int right = max(solve(node->right), 0);
        
        ans = max(ans, left + right + node->val);
        
        return max(left + node->val, right + node->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};