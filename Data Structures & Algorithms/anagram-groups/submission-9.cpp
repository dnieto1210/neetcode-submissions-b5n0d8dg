class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> myMap;

        for(string s : strs)
        {
            vector<int> count(26, 0);
            for(char c : s)
            {
                count[c-'a']++;
            }
            string key = "";

            for(int i = 0; i < count.size(); ++i)
            {
                key += to_string(count[i]) + ',';
            }

            myMap[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto kv: myMap)
        {
            result.push_back(kv.second);
        }

        return result;
        
    }
};
