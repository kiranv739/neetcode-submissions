class Twitter {

int timestamp = 0;
unordered_map<int,vector<pair<int,int>>>tweets;
unordered_map<int,unordered_set<int>>followers;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int>> pq;
        if(!tweets[userId].empty()){
            int idx = tweets[userId].size()-1;
            pq.push({tweets[userId][idx].first,userId,idx});
        }
        for(auto x : followers[userId]){
            if(!tweets[x].empty()){
                int idx = tweets[x].size()-1;
                pq.push({tweets[x][idx].first,x,idx});
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            auto [time,id,index] = pq.top();
            pq.pop();
            ans.push_back(tweets[id][index].second);
            if(index>0){
                index--;
                pq.push({tweets[id][index].first,id,index});
            } 
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
