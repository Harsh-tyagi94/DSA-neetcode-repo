class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> Queue;
        Queue.push(0);
        int farthest = 0;
        while(!Queue.empty()) {
            int i = Queue.front();
            Queue.pop();

            int start = max(i+minJump, farthest+1);
            int cutoff = min(i + maxJump + 1, n);
            for(int j=start;j<cutoff;j++) {
                if(s[j] == '0') {
                    if(j == n-1) return true;
                    Queue.push(j);
                }
            }

            farthest = i + maxJump;
        }
        return false;
    }
};