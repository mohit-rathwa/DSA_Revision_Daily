class Twitter {
    int time =0;
    unordered_map<int , vector<pair<int,int>> > tweets;
    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        for(auto tweet : tweets[userId]){
            pq.push(tweet);
            if(pq.size() > 10){
                pq.pop();
            }
        }
        for(auto follow : follows[userId]){
            for(auto tweet : tweets[follow]){
                pq.push(tweet);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }
        vector<int> tmp;
        while(!pq.empty()){
            int f = pq.top().second;
            pq.pop();
            tmp.push_back(f);
        }
        reverse(tmp.begin() ,tmp.end());

        return tmp;

    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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