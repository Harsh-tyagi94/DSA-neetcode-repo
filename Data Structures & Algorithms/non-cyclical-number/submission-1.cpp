class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long> uset;
        while(true) {
            string s = to_string(n);
            long sum = 0;
            for(auto num:s) {
                int val = (num-'0');
                sum += val*val;
            }
            if(sum == 1) return true;
            else if(uset.find(sum) != uset.end()) {
                break;
            }
            uset.insert(sum);
            n = sum;
        }
        return false;
    }
};
