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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head;
        ListNode* fast = head;

        while (fast and fast->next) {
            prev = curr;
            curr = curr->next;
            fast = fast->next->next;
        }

        if (prev == curr) return nullptr;

        prev->next = curr->next;
        delete curr;
        return head;
    }
};