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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* prev = sentinel;
        while (head) {
            if (head->next and head->val == head->next->val) {
                while (head->next and head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            }
            else {
                prev = head;
            }
            head = head->next;
        }

        return sentinel->next;
    }
};