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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = new ListNode(0, head);
        ListNode* l1 = ans;
        ListNode* l2 = ans;

        int dist = n;
        while (dist--) {
            l2 = l2->next;
        }

        while (l2->next) {
            l2 = l2->next;
            l1 = l1->next;
        }

        l1->next = l1->next->next;

        return ans->next;
    }
};