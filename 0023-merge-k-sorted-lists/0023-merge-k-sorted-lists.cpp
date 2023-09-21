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
typedef pair<int, ListNode*> pil;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil, vector<pil>, greater<pil>> pq;
        for (int i=0; i<lists.size(); ++i) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            head->next = node;
            head = head->next;
            
            if (node->next)
                pq.push({node->next->val, node->next});
        }
        return ans->next;
    }
};