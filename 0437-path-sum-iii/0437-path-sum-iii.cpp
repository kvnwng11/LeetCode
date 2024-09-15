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
    unordered_map<long long, int> prefixSums;

    int solve(TreeNode* curr, long long currSum, int targetSum) {
        if (!curr) return 0;

        currSum += curr->val;
        int ans = currSum == targetSum;
        ans += prefixSums[currSum - targetSum];

        prefixSums[currSum] += 1;
        
        ans += solve(curr->left, currSum, targetSum);
        ans += solve(curr->right, currSum, targetSum);

        prefixSums[currSum] -= 1;
        return ans;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};