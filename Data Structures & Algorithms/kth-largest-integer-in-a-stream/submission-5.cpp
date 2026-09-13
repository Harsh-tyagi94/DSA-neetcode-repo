class KthLargest {
    priority_queue<int, vector<int>, greater<>> qmin;
    int cap;
public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int num:nums) {
            if(qmin.size() < k) qmin.push(num);
            else {
                if(qmin.top() >= num) continue;
                qmin.pop();
                qmin.push(num);
            }
        }
    }
    
    int add(int val) {
        if(qmin.size() < cap) qmin.push(val);
        else {
            if(qmin.top() >= val) return qmin.top();
            qmin.pop();
            qmin.push(val);
        }
        return qmin.top();
    }
};
