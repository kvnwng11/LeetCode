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
    ListNode* firstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        
        ListNode* endFirstHalf = firstHalf(head);
        ListNode* startSecondHalf = reverse(endFirstHalf->next);
        
        ListNode *p1 = head;
        ListNode *p2 = startSecondHalf;
        while (p2) {
            if (p1->val != p2->val)
                return 0;
            p1 = p1->next;
            p2 = p2->next;
        }

        endFirstHalf = reverse(startSecondHalf);
        return 1;
    }
};