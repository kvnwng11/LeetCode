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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* ans = new ListNode(0);
        ListNode* sentinel = ans;

        int carry = 0;
        while (p1 && p2) {
            int sum = (p1->val + p2->val) + carry;
            int newVal = sum % 10;
            carry = sum / 10;

            ans->next = new ListNode(newVal);
            ans = ans->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1) {
            int sum = p1->val + carry;
            int newVal = sum % 10;
            carry = sum / 10;

            ans->next = new ListNode(newVal);
            ans = ans->next;
            p1 = p1->next;
        }

        while (p2) {
            int sum = p2->val + carry;
            int newVal = sum % 10;
            carry = sum / 10;

            ans->next = new ListNode(newVal);
            ans = ans->next;
            p2 = p2->next;
        }

        if (carry)
            ans->next = new ListNode(carry);

        return sentinel->next;
    }
};