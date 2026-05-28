class Node {
    int val;
    Node *next, *prev;
public:
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    friend class MyCircularQueue;
};

class MyCircularQueue {
public:
    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    int cap = 0, size = 0;
    MyCircularQueue(int k) {
        this->cap = k;
        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        size += 1;
        Node* newnode = new Node(value);
        Node* tail_prev = tail->prev;
        tail_prev->next = newnode;
        newnode->next = tail;
        newnode->prev = tail_prev;
        tail->prev = newnode;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        size -= 1;
        Node* next = head->next->next;
        head->next = next;
        next->prev = head;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return head->next->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        if(size) return false;
        return true;
    }
    
    bool isFull() {
        if(size == cap) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */