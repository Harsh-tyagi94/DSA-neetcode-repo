class Solution {
public:
    double myPow(double x, int n) {
        int original = n;
        n = abs(n);
        vector<pair<double,double>> vec;
        double pow = 1;
        vec.push_back({x, 1});
        while(2*pow <= n) {
            pow *= 2;
            double new_x = vec.back().first;
            vec.push_back({new_x*new_x, pow});
        }

        double res = 1;
        while(n>0) {
            double value = vec.back().first;
            pow = vec.back().second;
            vec.pop_back();

            if(n < pow) continue;
            n -= pow;
            if(original > 0) res *= value;
            else res /= value;
        }
        return res;
    }
};
