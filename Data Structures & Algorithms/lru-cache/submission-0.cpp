class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k_,int v_) {
            this->key = k_;
            this->value = v_;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;

    unordered_map<int,Node*> umap;

    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void AddNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void DeleteNode(Node* temp) {
        Node* delnext = temp->next;
        Node* delprev = temp->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) {
            return -1;
        }
        int val = umap[key]->value;
        DeleteNode(umap[key]);
        umap.erase(key);
        Node* curr = new Node(key,val);
        AddNode(curr);
        umap[key] = head->next;
        return val;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            //delete
            Node* curr = umap[key];
            DeleteNode(curr);
            //erase from umap;
            umap.erase(key);
        } else if(umap.size() == cap) {
            //erase
            umap.erase(tail->prev->key);
            //delete
            DeleteNode(tail->prev);
        }

        Node* curr = new Node(key,value);
        //add
        AddNode(curr);
        //umap
        umap[key] = head->next;
    }
};
