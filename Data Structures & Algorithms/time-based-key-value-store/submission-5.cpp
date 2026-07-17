class TimeMap {
public:
    TimeMap() {
        //n/a
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({value, timestamp});
        return;
        
    }
    
    string get(string key, int timestamp) {

        if(myMap.find(key) == myMap.end())
        {
            return "";
        }

        //otherwise key exists in the map
        vector<pair<string,int>> myVec = myMap[key];
        int left = 0;
        int right = myVec.size()-1;
        string temp = "";

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            pair<string, int> myPair = myVec[mid];
            if(myPair.second == timestamp)
            {
                return myPair.first;
            }
            else if(myPair.second > timestamp)
            {
                right = mid - 1;
            }
            else if(myPair.second < timestamp)
            {
                temp = myPair.first;
                left = mid + 1;
            }
        }

        return temp;
        
    }
private:
    unordered_map<string, vector<pair<string, int>>> myMap;
};
