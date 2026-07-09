class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<int> Stack;
        Stack.push_back(0);

        for(int t=1;t<n;t++) {
            while(!Stack.empty() && temperatures[Stack.back()] < temperatures[t]) {
                res[Stack.back()] = t - Stack.back();
                Stack.pop_back();
            }
            Stack.push_back(t);
        }
        return res;
    }
};