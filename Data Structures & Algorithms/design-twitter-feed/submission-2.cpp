class Twitter {
public:
    Twitter() {
        time = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        myTweets[userId].push({time, tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        ++time;

        priority_queue<Node, vector<Node>> maxHeap;
        vector<int> result;

        //put all elements of user inside maxHeap
        maxHeap = myTweets[userId];
        //put all tweets of users friends inside
        for(int f : myFriends[userId]) {
            //vector<Node> temp;
            priority_queue<Node, vector<Node>> check = myTweets[f];
            while(!check.empty()) {
                maxHeap.push(check.top());
                //temp.push_back(check.top());
                check.pop();
            }
        }

        while(!maxHeap.empty()) {
            if(result.size() == 10) {
                break;
            }

            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        ++time;
        if(followerId == followeeId) {
            return;
        }

        myFriends[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        ++time;
        if(followerId == followeeId) {
            return;
        }
        if(myFriends[followerId].find(followeeId) == myFriends[followerId].end()) {
            return;
        }
        myFriends[followerId].erase(followeeId);
        return;
    }
private:
    unordered_map<int,unordered_set<int>> myFriends;
    using Node = pair<int, int>; //time tweetId userId
    unordered_map<int, priority_queue<Node, vector<Node>>> myTweets;
    int time;
};
