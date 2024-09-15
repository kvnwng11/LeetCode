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
private:
    ListNode* reverse(ListNode* node) {
        if (!node or !node->next) return node;

        ListNode* rev = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return rev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow points to midpoint
        ListNode* reversed = reverse(slow);

        ListNode* l1 = reversed;
        ListNode* l2 = head;

        int ans = 0;
        while (l1 and l2) {
            ans = max(ans, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        return ans;
    }
};