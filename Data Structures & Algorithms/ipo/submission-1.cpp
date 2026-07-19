class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> combined;
        for(int i=0;i<n;i++) {
            combined.push_back({capital[i], profits[i]});
        }

        sort(combined.begin(), combined.end());
        priority_queue<int> pq;

        int total_capital = w, index = 0;
        while(k > 0) {
           while(index < combined.size() && combined[index][0] <= total_capital) {
                pq.push(combined[index][1]);
                index += 1;
            }

            if(pq.empty()) break;

            k -= 1;
            total_capital += pq.top();
            pq.pop();
        }
        return total_capital;
    }
};