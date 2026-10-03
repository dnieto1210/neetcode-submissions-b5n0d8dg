class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); ++i)
        {
            string key = "";
            string curr = strs[i];
            vector<int> count(26,0);
            for(char c: curr)
            {
                count[c-'a']++;
            }
            for(int j = 0; j < 26; ++j)
            {
                key += to_string(count[j]) + ',';
            }
            myMap[key].push_back(curr);
        }

        for(auto kv: myMap)
        {
            result.push_back(kv.second);
        }
        return result;
        
    }
};
