class Twitter {
public:
    Twitter() {
        time = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        maxHeap.push({time, {userId, tweetId}});
        following[userId].insert(userId);
        ++time; 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, pair<int,int>>> temp;
        //vector<pair<int, pair<int,int>>> unused;
        vector<int> result;

        while(!maxHeap.empty())
        {
            if(result.size() == 10)
            {
                break;
            }
            auto curr = maxHeap.top();
            int user = curr.second.first;
            int tweet = curr.second.second;
            if(following[userId].find(user) != following[userId].end())
            {
                //user is following this person
                result.push_back(tweet);
                temp.push_back({curr.first, {user, tweet}});
                maxHeap.pop();
            }
            else
            {
                temp.push_back({curr.first, {user, tweet}});
                maxHeap.pop();
            }
        }

        //restore heap
        for(int i = 0; i < temp.size(); ++i)
        {
            auto curr = temp[i];
            maxHeap.push({curr.first, {curr.second.first, curr.second.second}});
        }

        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
        {
            return;
        }
        following[followerId].erase(followeeId);
    }
private:
    int time;
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,unordered_set<int>> unfollowing;
    priority_queue<pair<int,pair<int,int>>> maxHeap;
};
