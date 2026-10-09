class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myKeys[key].push_back(timestamp);
        myVals[key][timestamp] = value;
        return;
    }
    
    string get(string key, int timestamp) {
        if(myKeys.find(key) == myKeys.end())
        {
            //key does not exist 
            return "";
        }
        vector<int> myTimes = myKeys[key];
        int left = 0;
        int right = myTimes.size()-1;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(myTimes[mid] == timestamp)
            {
                return myVals[key][timestamp];
            }
            else if(myTimes[mid] > timestamp)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        if(right < 0 || right > myTimes.size())
        {
            return "";
        }
        if(myTimes[right] > timestamp)
        {
            return "";
        }
        return myVals[key][myTimes[right]];
        
    }
private:
    unordered_map<string, vector<int>> myKeys;
    unordered_map<string, unordered_map<int, string>> myVals;
};
