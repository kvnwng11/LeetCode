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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (!root) return ans;

        vector<TreeNode*> level;
        level.push_back(root);

        while (!level.empty()) {
            vector<TreeNode*> newLevel;
            ans.push_back(level.back()->val);

            for (auto node : level) {
                if (node->left) newLevel.push_back(node->left);
                if (node->right) newLevel.push_back(node->right);
            }

            level = newLevel;
        }

        return ans;
    }
};