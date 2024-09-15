/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int ans = 0;
        int n = nums.size();
        for (int i=0; i<n/2; ++i) {
            int other = (n - 1 - i);
            ans = max(ans, nums[i] + nums[other]);
        }
        return ans;
    }
};