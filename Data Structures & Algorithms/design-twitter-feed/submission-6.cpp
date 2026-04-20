class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> postList;
    unordered_map<int, unordered_set<int>> followList;
    int k = 1;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postList[userId].push_back({k++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> qmax;
        for(auto post:postList[userId]) {
            qmax.push(post);
        }
        for(int followeeId:followList[userId]) {
            for(auto post:postList[followeeId]) {
                qmax.push(post);
            }
        }
        vector<int> res;
        for(int i=0;i<10;i++) {
            if(qmax.empty()) return res;
            res.push_back(qmax.top().second);
            qmax.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followList[followerId].erase(followeeId);
    }
};
