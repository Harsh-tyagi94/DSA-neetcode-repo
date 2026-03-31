class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> qmax;
        for(int stone:stones) {
            qmax.push(stone);
        }

        while(!qmax.empty() && qmax.size() > 1) {
            int y = qmax.top(); qmax.pop();
            int x = qmax.top(); qmax.pop();

            if(x != y) {
                qmax.push(y-x);
            }
        }

        return qmax.empty() ? 0 : qmax.top();
    }
};