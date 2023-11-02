/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB)
            return nullptr;

        unordered_set<ListNode*> v;

        while (headA) {
            v.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (v.count(headB))
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};