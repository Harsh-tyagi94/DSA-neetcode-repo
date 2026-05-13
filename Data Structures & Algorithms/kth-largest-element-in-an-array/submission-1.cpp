class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> qmin;
        for(int n:nums) {
            qmin.push(n);
            if(qmin.size() > k) qmin.pop();
        }

        return qmin.top();
    }
};