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

        deque<TreeNode*> level;
        level.push_back(root);

        while (!level.empty()) {
            int size = level.size();
            ans.push_back(level.back()->val);

            for (int i=0; i<size; ++i) {
                TreeNode* node = level.front();
                level.pop_front();
                if (node->left) level.push_back(node->left);
                if (node->right) level.push_back(node->right);
            }
        }

        return ans;
    }
};