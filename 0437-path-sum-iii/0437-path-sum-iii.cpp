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
    int ans = 0;
    unordered_map<long, int> numSeen;

    void solve(TreeNode* curr, long currSum, int targetSum) {
        if (!curr) return;

        currSum += curr->val;

        if (currSum == targetSum)
            ans++;
        
        ans += numSeen[currSum - targetSum];
        numSeen[currSum] += 1;

        solve(curr->left, currSum, targetSum);
        solve(curr->right, currSum, targetSum);

        numSeen[currSum] -= 1;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        solve(root, 0, targetSum);
        return ans;
    }
};