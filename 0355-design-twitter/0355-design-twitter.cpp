class Twitter {
public:
    using p = pair<int, int>;
    unordered_map<int, unordered_set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time = 0;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<p> v = tweets[userId];
        for (auto it : v) {
            pq.push(it);
            if (pq.size() > 10) {
                pq.pop();
            }
        }
        for (auto it : follower[userId]) {
            for (auto temp : tweets[it]) {
                pq.push(temp);

                if (pq.size() > 10)
                    pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (follower[followerId].find(followeeId) !=
            follower[followerId].end()) {
            follower[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */