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
    ListNode* reverseSegment(ListNode* head, int k) {
        ListNode* newHead = nullptr;
        ListNode* curr = head;
        while (k > 0) {
            ListNode* tmp = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = tmp;
            k--;
        }

        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* ktail = nullptr;
        ListNode* newHead = nullptr;
        while (curr) {
            int count = 0;
            curr = head;
            while (count < k && curr) {
                curr = curr->next;
                count++;
            }

            if (count == k) {
                ListNode* revSeg = reverseSegment(head, k);
                if (!newHead) newHead = revSeg;
                if (ktail) ktail->next = revSeg;
                ktail = head;
                head = curr;
            }
        }

        if (ktail) ktail->next = head;
        return !newHead? head : newHead;
    }
};