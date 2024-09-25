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
    void serialize(TreeNode* node, string &str) {
        if (!node) {
            str += '#';
            return;
        }

        str += '^';
        str += to_string(node->val);
        serialize(node->left, str);
        serialize(node->right, str);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s = "";
        serialize(root, s);
        string t = "";
        serialize(subRoot, t);

        return s.find(t) != string::npos;
    }
};