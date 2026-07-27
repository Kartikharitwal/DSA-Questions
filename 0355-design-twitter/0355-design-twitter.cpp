class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    // {user_id,{time,tweetId}}
    int time = 0;
    unordered_map<int, unordered_set<int>> followers;
    // {followerId--->>followeeId}
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Add user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);

            if (pq.size() > 10)
                pq.pop();
        }

        // Add tweets of all followees
        for (auto followee : followers[userId]) {
            for (auto tweet : tweets[followee]) {

                pq.push(tweet);

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second); // tweetId
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].find(followeeId) !=
            followers[followerId].end()) {
            followers[followerId].erase(followeeId);
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