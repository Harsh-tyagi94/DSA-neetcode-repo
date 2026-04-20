class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> character(26,0);
        for(int t:tasks) {
            character[t-'A']++;
        }

        priority_queue<int> qmax;
        for(int ch:character) {
            if(ch) qmax.push(ch);
        }

        queue<pair<int,int>> Queue;
        int time = 0;
        while(!qmax.empty() || !Queue.empty()) {
            time++;
            if(!Queue.empty() && Queue.front().second < time) {
                qmax.push(Queue.front().first);
                Queue.pop();
            }

            if(!qmax.empty()) {
                if(qmax.top() > 1) {
                    Queue.push({qmax.top()-1,time+n});
                }
                qmax.pop();
            }
        }
        return time;
    }
};