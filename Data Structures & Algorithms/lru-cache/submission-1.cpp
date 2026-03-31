class Node{
    int key, value;
    Node* next;
    Node* prev;
public:
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

    friend class LRUCache;
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> ump;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void DeleteNode(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    void AddNode(Node* curr) {
        curr->next = head->next;
        head->next->prev = curr;
        curr->prev = head;
        head->next = curr;
    }
    
    int get(int key) {
        if(!ump.count(key)) return -1;

        Node* curr = ump[key];
        DeleteNode(curr);
        ump.erase(key);

        int val = curr->value;
        Node* newnode = new Node(key, val);
        AddNode(newnode);

        ump[key] = head->next;
        return val;
    }
    
    void put(int key, int value) {
        if(!ump.count(key)) {
            if(ump.size() == cap) {
                ump.erase(tail->prev->key);
                DeleteNode(tail->prev);
            }
        } else {
            DeleteNode(ump[key]);
            ump.erase(key);
        }

        Node* newnode = new Node(key, value);
        AddNode(newnode);

        ump[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */