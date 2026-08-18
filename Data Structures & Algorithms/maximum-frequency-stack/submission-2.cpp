class FreqStack {
public:
    unordered_map<int, int> eleFreq;
    unordered_map<int, vector<int>> ele_val;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        ele_val[++eleFreq[val]].push_back(val);
        maxFreq = max(maxFreq, eleFreq[val]);
    }
    
    int pop() {
        if(!maxFreq) return -1;
        int val = ele_val[maxFreq].back();
        eleFreq[val] -= 1;
        ele_val[maxFreq].pop_back();
        if(!ele_val[maxFreq].size()) maxFreq -= 1;
        return val;
    }
};

/*
eleFreq {
    1: 2, 2: 2,
}

ele_val {
    1: [ 1, 2 ],
    2: [ 2, 1 ],
    3: [ 2 ]
}


*/

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */