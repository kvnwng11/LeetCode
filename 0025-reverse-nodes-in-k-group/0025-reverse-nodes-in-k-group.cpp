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
    ListNode* reverseSegment(ListNode* start, ListNode* end) {
        // [start, end]
        //if (!start or !end) return start;
        cout << start->val << " " << end->val << endl;

        ListNode* after = end->next;

        ListNode* curr = start;
        ListNode* prev = nullptr;

        while (curr != after) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        start->next = after;

        // Maybe change?
        return end;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(-1, head);
        ListNode* left = ans;
        ListNode* right = ans;

        for (int i=0; i<k; ++i)
            right = right->next;


        while (right) {
            left->next = reverseSegment(left->next, right);


            left = left->next;
            right = left;

            for (int i=0; i<k; ++i)
                right = right->next; 

            for (int i=0; i<k-1; ++i) {
                if (!right)
                    break;
                    
                left = left->next;
                right = right->next; 
            }
        }

        return ans->next;
    }
};