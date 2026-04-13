class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({timestamp, value});
        
    }
    
    string get(string key, int timestamp) {
        std::vector<std::pair<int, string>> vec = myMap[key];
        string result = "";

        int left = 0;
        int right = vec.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(vec[mid].first <= timestamp)
            {
                result = vec[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
        
    }
private:
    std::unordered_map<string, std::vector<std::pair<int, string>>> myMap;
};
