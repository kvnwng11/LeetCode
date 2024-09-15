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
    queue<pair<TreeNode*, int>> q;
    int ans = 0;

    int recurse() {
        if (q.empty()) return ans;

        auto [node, level] = q.front();
        q.pop();

        if (node->left)
            q.push({node->left, level+1});
        if (node->right)
            q.push({node->right, level+1});

        ans = max(level, ans);
        
        return recurse();
    }

public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int ans = 1;
        q.push({root, 1});

        return recurse();
    }
};