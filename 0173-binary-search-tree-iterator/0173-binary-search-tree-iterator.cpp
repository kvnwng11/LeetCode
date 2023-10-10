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
class BSTIterator {
private:
    deque<TreeNode*> d;

public:
    BSTIterator(TreeNode* root) {
        while (root) {
            d.push_front(root);
            root = root->left;
        }
    }
    
    int next() {
        int res = d.front()->val;
        TreeNode* curr = d.front();
        d.pop_front();

        if (curr->right) {
            curr = curr->right;
            while (curr) {
                d.push_front(curr);
                curr = curr->left;
            }
        }

        return res;
    }
    
    bool hasNext() {
        return d.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */