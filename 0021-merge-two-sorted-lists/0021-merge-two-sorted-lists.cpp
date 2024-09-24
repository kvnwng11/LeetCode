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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* sentinel = head;

        while (list1 and list2) {
            if (list1->val < list2->val) {
                sentinel->next = list1;
                list1 = list1->next;
            }
            else {
                sentinel->next = list2;
                list2 = list2->next;
            }
            sentinel = sentinel->next;
        }

        while (list1) {
            sentinel->next = list1;
            list1 = list1->next;
            sentinel = sentinel->next;
        }

        while (list2) {
            sentinel->next = list2;
            list2 = list2->next;
            sentinel = sentinel->next;
        }

        return head->next;
    }
};