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
    ListNode* getMid(ListNode *n) {
        ListNode* slow = n;
        ListNode* fast = n->next;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;

        // Get mid
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;


        // Sort
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(right);

        // Merge
        ListNode* ans = new ListNode(0);
        ListNode* sentinel = ans;

        while (l1 and l2) {
            if (l1->val < l2->val) {
                ans->next = l1;
                l1 = l1->next;
            }
            else {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        while (l1) {
            ans->next = l1;
            l1 = l1->next;
            ans = ans->next;
        }
        while (l2) {
            ans->next = l2;
            l2 = l2->next;
            ans = ans->next;
        }
        return sentinel->next;
    }
};