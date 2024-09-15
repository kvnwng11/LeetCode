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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* oddSentinel = odd;
        ListNode* evenSentinel = even;

        int idx = 1;
        while (head) {
            if (idx % 2 == 0) {
                even->next = head;
                even = even->next;
            }
            else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            idx++;
        }

        odd->next = evenSentinel->next;
        even->next = nullptr;

        return oddSentinel->next;
    }
};