class Node {
    int val,key;
    Node *next, *prev;
public:
    Node(int key,int val) {
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
    }
    friend class LRUCache; 
};

class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int capacity = 0;
    unordered_map<int, Node*> ump;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode) {
        newnode->next = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next->prev = newnode;
        return;
    }

    void deletenode(Node* curr) {
        Node* prevnode = curr->prev;
        Node* nextnode = curr->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        delete curr;
        return;
    }
    
    int get(int key) {
        if(ump.count(key)) {
            int value = ump[key]->val;
            deletenode(ump[key]);
            ump.erase(key);
            Node* newnode = new Node(key, value);
            addnode(newnode);
            ump[key] = head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* newnode = new Node(key, value);
        if(ump.count(key)) {
            deletenode(ump[key]);
            ump.erase(key);
        } else {
            if(capacity == ump.size()) {
                ump.erase(tail->prev->key);
                deletenode(tail->prev);
            }
        }
        addnode(newnode);
        ump[key] = head->next;
    }
};

