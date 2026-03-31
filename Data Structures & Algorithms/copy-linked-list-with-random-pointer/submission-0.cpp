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
    void insertNode(Node* &copy, Node* &insert_tail, int d) {
        Node* newnode = new Node(d);
        if(!copy) {
            copy = newnode;
            insert_tail = copy;
        } else {
            insert_tail->next = newnode;
            insert_tail = insert_tail->next;
        }
    }
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* temp = head;
        Node* copy = nullptr;
        Node* insert_tail = nullptr;
        while(temp) {
            insertNode(copy,insert_tail,temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* DeepCopy = copy;
        while(temp) {
            Node* DeepCopyNext = DeepCopy->next;
            DeepCopy->next = temp->next;
            temp->next = DeepCopy;
            DeepCopy = DeepCopyNext;
            temp = temp->next->next;
        }

        temp = head;
        while(temp) {
            temp->next->random = (!temp->random) ? nullptr : temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        DeepCopy = temp->next;
        while(temp) {
            temp->next = DeepCopy->next;
            temp = temp->next;
            if(temp) DeepCopy->next = temp->next;
            DeepCopy = DeepCopy->next;
        }
        return copy;
    }
};