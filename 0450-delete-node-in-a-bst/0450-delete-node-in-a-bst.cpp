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
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left) root = root->left;
        return root->val;
    }

    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right) root = root->right;
        return root->val;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {
            if (!root->left and !root->right) {
                root = nullptr;
            }
            else if (root->right) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
            
        }
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);

        return root;
    }
};