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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int maxSum = INT_MIN;

        deque<TreeNode*> d;
        d.push_back(root);
        int currLevel = 1;

        while (!d.empty()) {
            int size = d.size();
            int sum = 0;

            for (int i=0; i<size; ++i) {
                TreeNode* curr = d.front();
                d.pop_front();

                sum += curr->val;

                if (curr->left) d.push_back(curr->left);
                if (curr->right) d.push_back(curr->right);
            }

            if (sum > maxSum) {
                level = currLevel;
                maxSum = sum;
            }

            currLevel++;
        }

        return level;
    }
};