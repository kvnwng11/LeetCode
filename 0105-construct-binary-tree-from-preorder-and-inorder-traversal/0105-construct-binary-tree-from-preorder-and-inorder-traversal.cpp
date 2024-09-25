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
    unordered_map<int, int> inorderToIndex;
    int i = 0;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[i++];
        TreeNode* root = new TreeNode(rootValue);

        root->left = arrayToTree(preorder, left, inorderToIndex[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderToIndex[rootValue] + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        for (int i=0; i<inorder.size(); ++i) {
            inorderToIndex[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size()-1);
    }
};