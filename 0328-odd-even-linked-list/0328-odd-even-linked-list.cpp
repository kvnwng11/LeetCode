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
        ListNode* sentinelEven = new ListNode(-1);
        ListNode* sentinelOdd = new ListNode(-1);

        ListNode* even = sentinelEven;
        ListNode* odd = sentinelOdd;

        bool isOdd = true;
        while (head) {
            if (isOdd) {
                cout << "odd\n";
                odd->next = head;
                odd = odd->next;
            }
            else {
                cout << "even\n";
                even->next = head;
                even = even->next;
            }
            isOdd = !isOdd;
            head = head->next;
        }
        even->next = nullptr;


        odd->next = sentinelEven->next;

        return sentinelOdd->next;
    }
};