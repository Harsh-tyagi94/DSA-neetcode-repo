class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for(int i=0;i<n;i++) {
            free_rooms.push(i);
        }

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> qmin;
        vector<long long> res(n, 0);
        long long max_rooms = 0;
        for(int i=0;i<meetings.size();i++) {
            while(!qmin.empty() && meetings[i][0] >= qmin.top()[0]) {
                free_rooms.push(qmin.top()[1]);
                qmin.pop();
            }

            int room_no = 0;
            if(free_rooms.empty()) {
                room_no = qmin.top()[1];
                long long interval = qmin.top()[0] + (meetings[i][1] - meetings[i][0]);
                qmin.pop();
                qmin.push({interval, room_no});
            } else {
                room_no = free_rooms.top();
                free_rooms.pop();
                qmin.push({meetings[i][1], room_no});
            }

            res[room_no] += 1;
            cout<<"room_number:"<<room_no<<endl;
            max_rooms = max(max_rooms, res[room_no]);
        }

        for(int i=0;i<n;i++) {
            if(max_rooms == res[i]) return i;
        }

        return -1;
    }
};