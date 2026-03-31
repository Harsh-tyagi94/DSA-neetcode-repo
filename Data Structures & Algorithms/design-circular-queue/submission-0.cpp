class Node {
    int val;
    Node* next;
    Node* prev;
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
    int capacity = 0;
    int curr_len = 0;
    MyCircularQueue(int k) {
        capacity = k;
        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        Node* newNode = new Node(value);
        if(curr_len == capacity) {
            return false;
        }

        Node* tailPrev = tail->prev;
        tailPrev->next = newNode;
        newNode->prev = tailPrev;
        newNode->next = tail;
        tail->prev = newNode;
        curr_len += 1;
        return true;
    }
    
    bool deQueue() {
        if(curr_len == 0) return false;

        head = head->next;
        head->prev = nullptr;
        curr_len -= 1;
        return true;
    }
    
    int Front() {
        if(curr_len == 0) return -1;

        return head->next->val;
    }
    
    int Rear() {
        if(curr_len == 0) return -1;

        return tail->prev->val;
    }
    
    bool isEmpty() {
        return curr_len == 0;
    }
    
    bool isFull() {
        return curr_len == capacity;
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