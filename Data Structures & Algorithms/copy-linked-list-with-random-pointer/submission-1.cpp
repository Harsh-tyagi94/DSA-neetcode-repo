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
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* temp = head;
        while(temp) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp) {
            if(temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        temp = head;
        Node* copy = head->next;
        Node* clone = copy;
        while(temp) {
            temp->next = clone->next;
            temp = temp->next;
            if(temp) clone->next = temp->next;
            clone = clone->next;
        }
        return copy;
    }
};
