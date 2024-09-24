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
        if (!head || !head->next) return head;

        ListNode* end = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return end;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find second half
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = reverse(slow);
       
        // Merge
        ListNode* first = head;
        ListNode* second = secondHalf;
        while (second->next) {
            ListNode* next1 = first->next;
            first->next = second;
            first = next1;

            ListNode* next2 = second->next;
            second->next = first;
            second = next2;
        }
    }
};