class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        if(left.size() - right.size() > 1) {
            right.push(left.top());
            left.pop();
        } else if(!right.empty() && right.top() < left.top()) {
            int curr = left.top(); left.pop();
            left.push(right.top());
            right.pop();
            right.push(curr);
        }

        return;
    }
    
    double findMedian() {
        int total = left.size() + right.size();

        if(total%2) {
            return double(left.top());
        }

        return double(left.top()+right.top())/2.0;
    }
};