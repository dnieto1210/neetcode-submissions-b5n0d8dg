class TimeMap {
public:
    TimeMap() {
        //map
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {

        vector<pair<int, string>>& curr = myMap[key];
        int left = 0;
        int right = curr.size()-1;

        int maxTime = INT_MIN;
        string res = "";
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(curr[mid].first == timestamp)
            {
                return curr[mid].second;
            }
            else if(curr[mid].first > timestamp)
            {
                right = mid-1;
            }
            else
            {
                if(curr[mid].first > maxTime)
                {
                    maxTime = curr[mid].first;
                    res = curr[mid].second;
                }
                left = mid+1;
            }
        }

        return res;
        
    }
private:
    unordered_map<string, vector<pair<int, string>> > myMap;
};
