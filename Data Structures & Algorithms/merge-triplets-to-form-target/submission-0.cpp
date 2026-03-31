class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> triple_curr = {1,1,1};

        for(auto triple:triplets) {
            if(triple[0] > target[0] || triple[1] > target[1] || triple[2] > target[2]) continue;
            int a = max(triple_curr[0],triple[0]);
            int b = max(triple_curr[1],triple[1]);
            int c = max(triple_curr[2],triple[2]);
            triple_curr = {a,b,c};
        }

        return triple_curr == target;
    }
};