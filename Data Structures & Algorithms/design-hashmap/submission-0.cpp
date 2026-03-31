class LinkNode {
    int key, val;
    LinkNode* next;
public:
    LinkNode(int key,int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
    }
    friend class MyHashMap;
};

class MyHashMap {
public:
    vector<LinkNode*> mapping;
    int mod = 1000;
    MyHashMap() {
        mapping.resize(mod,nullptr);
    }
    
    void put(int key, int value) {
        int k = key;
        key %= mod;
        LinkNode* head = mapping[key];
        while(head) {
            if(head->key == k) {
                head->val = value;
                return;
            }
            head = head->next;
        }

        LinkNode* p = new LinkNode(k,value);
        p->next = mapping[key];
        mapping[key] = p;
    }
    
    int get(int key) {
        int k = key;
        key %= mod;
        LinkNode* head = mapping[key];
        while(head) {
            if(head->key == k) {
                return head->val;
            }
            head = head->next;
        }

        return -1;
    }
    
    void remove(int key) {
        int k = key;
        key %= mod;
        LinkNode* prev = nullptr;
        LinkNode* head = mapping[key];
        while(head) {
            if(head->key == k) {
                if(prev) prev->next = head->next;
                else mapping[key] = head->next;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */