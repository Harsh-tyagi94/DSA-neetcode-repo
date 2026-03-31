class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();

        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top().first < temperatures[i]) {
                temperatures[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
            temperatures[i] = 0;
        }

        return temperatures;
    }
};
