class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> qmin;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int n:nums) {
            if(qmin.size() == k) {
                if(qmin.top() < n) {
                    qmin.pop();
                    qmin.push(n);
                }
                continue;
            }
            qmin.push(n);
        }
    }
    
    int add(int val) {
        if(qmin.size() == k) {
            if(qmin.top() < val) {
                qmin.pop();
                qmin.push(val);
            }
        } else {
            qmin.push(val);
        }

        return qmin.size() < k ? -1 : qmin.top();
    }
};
