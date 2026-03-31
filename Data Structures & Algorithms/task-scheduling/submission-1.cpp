class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> uom;
        for(auto t:tasks){
            uom[t]++;
        }
        priority_queue<int> pq;
        for(auto p:uom){
            pq.push(p.second);
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && q.front().second<time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                if(pq.top()>1){
                    q.push({pq.top()-1,time+n});
                }
                pq.pop();
            }
        }
        return time;
    }
};
