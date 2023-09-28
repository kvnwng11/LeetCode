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
    vector<TreeNode*> nodes;

    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p and !q) return 1;
        if (!p or !q) return 0;
        if (p->val != q->val) return 0;
        return isSame(p->left, q->left) and isSame(p->right, q->right);
    }

    int getDepth(TreeNode* n, int target) {
        if (!n) return -1;
        int depth = max(getDepth(n->left, target), getDepth(n->right, target)) + 1;

        if (depth == target)
            nodes.push_back(n);
        
        return depth;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return 1;
        if (!root or !subRoot) return 0;
        getDepth(root, getDepth(subRoot, -1));
        for (TreeNode* node : nodes)
            if (isSame(subRoot, node))
                return 1;
        return 0;
    }
};