class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(auto ast:asteroids) {
            while(!st.empty() && ast<0 && st.back() > 0) {
                int diff = ast + st.back();

                if(diff < 0) {
                    st.pop_back();
                } else if(diff > 0) {
                    ast = 0;
                } else {
                    ast = 0;
                    st.pop_back();
                }
            }
            if(ast != 0) st.push_back(ast);
        }

        return st;
    }
};