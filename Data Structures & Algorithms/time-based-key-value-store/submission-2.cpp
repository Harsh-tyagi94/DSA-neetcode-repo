class Node {
    string val;
    int time_st;
    Node* next;
public:
    Node(string value,int timestamp) {
        this->val = value;
        this->time_st = timestamp;
        this->next = nullptr;
    }

    friend class TimeMap;
};

class TimeMap {
public:
    unordered_map<string, Node*> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Node* curr = new Node(value,timestamp);
        if(!mp.count(key)) {
            mp[key] = curr;
            return;
        }
        Node* head = mp[key];
        // if(!head) {
        //     mp[key] = head;
        //     return;
        // }

        curr->next = head;
        mp[key] = curr;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";

        Node* head = mp[key];
        while(head != nullptr && head->time_st > timestamp) {
            head = head->next;
        }

        return head == nullptr ? "" : head->val;
    }
};