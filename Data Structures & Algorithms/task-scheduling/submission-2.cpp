class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> character(26,0);

        for(char task:tasks) {
            character[task-'A']++;
        }

        priority_queue<int> qmax;
        for(int ch:character) {
            if(ch != 0) qmax.push(ch);
        }

        int time = 0;
        queue<pair<int,int>> q;
        while(!qmax.empty() || !q.empty()) {
            time++;

            if(qmax.empty()) {
                time = q.front().second;
            } else {
                int t = qmax.top()-1;
                qmax.pop();
                if(t > 0) {
                    q.push({t,time+n});
                }
            }

            if(!q.empty() && q.front().second == time) {
                qmax.push(q.front().first);
                q.pop();
            }
            // vector<int> dummy;
            // for(int i=0;i<=n;i++) {
            //     if(qmax.empty()) {
            //         if(dummy.size() == 0) return time;
            //         time += n-i+1;
            //         break;
            //     }
            //     int t = qmax.top();
            //     qmax.pop();
            //     if(t > 1) dummy.push_back(t-1);
            //     time += 1;
            // }

            // for(int d:dummy) {
            //     qmax.push(d);
            // }
        }

        return time;
    }
};
