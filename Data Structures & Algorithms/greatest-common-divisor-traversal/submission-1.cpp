class Solution {
public:
    int findgcd(int a, int b) {
        if(b == 0) return a;
        if(b == 1) return b;
        return findgcd(b, a%b);
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> adj;
        unordered_set<int> unique_num;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(findgcd(nums[i], nums[j]) > 1) {
                    adj[nums[i]].push_back(nums[j]);
                    adj[nums[j]].push_back(nums[i]);
                }
                unique_num.insert(nums[i]);
                unique_num.insert(nums[j]);
            }
        }

        if(unique_num.size() == 1 && *unique_num.begin() == 1) return false;

        queue<int> Queue;
        Queue.push(*unique_num.begin());
        unique_num.erase(Queue.front());

        while(!unique_num.empty()) {
            if(Queue.empty()) return false;
            int len = Queue.size();
            for(int i=0;i<len;i++) {
                int curr = Queue.front();
                Queue.pop();

                for(int neighbor:adj[curr]) {
                    if(unique_num.count(neighbor)) {
                        Queue.push(neighbor);
                        unique_num.erase(neighbor);
                    }
                }
            }
        }
        
        return true;
    }
};