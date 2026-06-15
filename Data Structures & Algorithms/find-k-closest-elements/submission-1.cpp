class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        queue<int> q;
        q.push(arr[0]);
        for(int i=1;i<arr.size();i++) {
            int absolute = abs(arr[i]-x);
            if(q.size() == k && absolute >= abs(q.front()-x)) continue;
            else if(q.size() == k) q.pop();
            q.push(arr[i]);
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};