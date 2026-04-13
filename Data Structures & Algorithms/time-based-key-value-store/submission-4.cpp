class TimeMap {
public:
    TimeMap() {
        //n/a
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        vector<pair<string, int>> temp = myMap[key];
        if(temp.size() == 0)
        {
            return "";
        }

        int left = 0;
        int right = temp.size()-1;
        string r = "";

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            pair<string, int> p = temp[mid];
            string v = p.first;
            int t = p.second;

            if(t <= timestamp)
            {
                r = v;
                left = mid+1;
            }
            else
            {
                //t > timestamp
                right = mid-1;
            }
        }

        return r;
    }
private:

    unordered_map<string, vector<pair<string, int>>> myMap;
};
