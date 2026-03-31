class Twitter {
    int count;
    unordered_map<int,vector<pair<int,int>>> postList;
    unordered_map<int,set<int>> followList;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        postList[userId].push_back({++count,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;

        // include own posts
        for (auto post : postList[userId]) {
            pq.push({post.first, post.second});
        }

        // include followee posts
        for (auto followee : followList[userId]) {
            for (auto post : postList[followee]) {
                pq.push({post.first, post.second});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followList[followerId].erase(followeeId);
    }
};