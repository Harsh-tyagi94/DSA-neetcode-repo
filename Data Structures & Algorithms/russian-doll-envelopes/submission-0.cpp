class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int n = envelopes.size();
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++) {
            if(temp.back() < envelopes[i][1]) temp.push_back(envelopes[i][1]);
            else {
                int index = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                temp[index] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};

/*
5: 4,
6: 7,4
2: 3


*/