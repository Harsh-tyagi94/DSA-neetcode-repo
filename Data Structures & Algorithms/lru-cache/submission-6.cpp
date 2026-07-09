class Node {
    int key, val;
    Node* next; Node* prev;
public:
    Node(int key, int val) {
        this->key = key; this->val = val;
        next = nullptr; prev = nullptr;
    }

    friend class LRUCache;
};

class LRUCache {
public:
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> ump;
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* curr) {
        if(!curr) return;

        Node* temp = curr->next;
        curr->prev->next = temp;
        temp->prev = curr->prev;
        return;
    }

    void addnode(Node* curr) {
        if(!curr) return;

        Node* temp = head->next;
        curr->next = temp;
        curr->prev = head;
        temp->prev = curr;
        head->next = curr;
        return;
    }
    
    int get(int key) {
        if(!ump.count(key)) return -1;

        int value = ump[key]->val;
        deletenode(ump[key]);
        
        Node* newnode = new Node(key, value);
        addnode(newnode);
        ump[key] = head->next;
        return value;
    }
    
    void put(int key, int value) {
        if(!ump.count(key)) {
            if(ump.size() == cap) {
                int k = tail->prev->key;
                deletenode(tail->prev);
                ump.erase(k);
            }
        } else {
            deletenode(ump[key]);
            ump.erase(key);
        }
        
        Node* newnode = new Node(key, value);
        addnode(newnode);
        ump[key] = head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */