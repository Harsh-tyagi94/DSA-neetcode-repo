class MinStack {
public:
    vector<pair<int, int>> Stack;
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = val;
        if(!Stack.empty()) minVal = min(Stack.back().second, minVal);
        Stack.push_back({val, minVal});
        return;
    }
    
    void pop() {
        if(!Stack.empty()) Stack.pop_back();
        return;
    }
    
    int top() {
        if(Stack.empty()) return NULL;
        return Stack.back().first;
    }
    
    int getMin() {
        if(Stack.empty()) return NULL;
        return Stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */