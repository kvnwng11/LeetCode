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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (head) {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* l1 = head;
        ListNode* l2 = head;
        while (l2) {
            l1 = l1->next;
            l2 = l2->next;
            if (l2) l2 = l2->next;
        }

        ListNode* half = reverse(l1);

        while (half) {
            if (head->val != half->val)
                return 0;
            head = head->next;
            half = half->next;
        }

        return 1;
    }
};