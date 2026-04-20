class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> Stack;
        Stack.push_back({INT_MAX, -1});
        for(int t=0;t<temperatures.size();t++) {
            int temp = temperatures[t];
            temperatures[t] = 0;
            while(Stack.back().first < temp) {
                temperatures[Stack.back().second] = t - Stack.back().second;
                Stack.pop_back();
            }
            Stack.push_back({temp, t});
        }
        return temperatures;
    }
};
