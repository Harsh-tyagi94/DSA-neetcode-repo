class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int n:nums) {
            if(uset.count(n)) return true;
            uset.insert(n);
        }
        return false;
    }
};