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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return 1;
        if (!root or !subRoot) return 0;

        if (root->val != subRoot->val)
            return 0;

        bool l = isSameTree(root->left, subRoot->left);
        bool r = isSameTree(root->right, subRoot->right);
        
        return l and r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return 1;
        if (!root or !subRoot) return 0;

        if (isSameTree(root, subRoot)) {
            return 1;
        }
        
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};