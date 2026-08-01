class Node{
    int key, value, count;
    Node *prev, *next;

    Node(int k, int v) {
        this->key = k;
        this->value = v;
        this->count = 1;
    }

    friend class List;
    friend class LFUCache;
};

class List{
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void DeleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;

        delprev->next = delnext;
        delnext->prev = delprev;
        --size;
    }

    void AddNode(Node* newNode){
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = temp->prev = newNode;
        ++size;
    }
};

class LFUCache {
public:
    int capacity, minFreq, currSize;
    unordered_map<int, List*> freqListMap;
    unordered_map<int, Node*> keyNodeMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void UpdateNode(Node* node){
        List* currFreqList = freqListMap[node->count];
        currFreqList->DeleteNode(node);

        if(node->count == minFreq && currFreqList->size == 0)
            ++minFreq;

        node->count += 1;
        List *nextFreqList;

        if(freqListMap.count(node->count)){
            nextFreqList = freqListMap[node->count];
            nextFreqList->AddNode(node);
        }
        else{
            nextFreqList = new List();
            nextFreqList->AddNode(node);
            freqListMap[node->count] = nextFreqList;
        }
    }

    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end())
            return -1;
        
        Node* keyNode = keyNodeMap[key];
        UpdateNode(keyNode);
        return keyNode->value;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            Node* keyNode = keyNodeMap[key];
            keyNode->value = value;
        }
        else{
            if(currSize == capacity){
                List* minFreqList = freqListMap[minFreq];
                keyNodeMap.erase(minFreqList->tail->prev->key);
                minFreqList->DeleteNode(minFreqList->tail->prev);
                --currSize;
            }

            ++currSize;
            minFreq = 1;

            List* freqList;
            if(freqListMap.find(minFreq) != freqListMap.end())
                freqList = freqListMap[minFreq];
            else
                freqList = new List();

            Node* newNode = new Node(key, value);
            freqList->AddNode(newNode);
            freqListMap[minFreq] = freqList;
            keyNodeMap[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */