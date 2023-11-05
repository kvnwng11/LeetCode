/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> toNew;

public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (toNew.count(head)) return toNew[head];

        Node* n = new Node(head->val);
        toNew[head] = n;
        
        if (head->next)
            n->next = copyRandomList(head->next);
        if (head->random)
            n->random = copyRandomList(head->random);

        return n;
    }
};