class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool is_a = false;
        bool is_b = false;
        bool is_c = false;

        for(auto triple:triplets) {
            is_a |= (triple[0] == target[0] && triple[1] <= target[1] && triple[2] <= target[2]);
            is_b |= (triple[1] == target[1] && triple[0] <= target[0] && triple[2] <= target[2]);
            is_c |= (triple[2] == target[2] && triple[0] <= target[0] && triple[1] <= target[1]);
        }

        return is_a && is_b && is_c;
    }
};