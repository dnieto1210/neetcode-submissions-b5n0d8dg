class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> myMap;

        for(int i = 0; i < strs.size(); ++i)
        {
            string curr = strs[i];
            vector<int> temp(26, 0);
            for(char c: curr)
            {
                temp[c-'a']++;
            }
            string key = "";

            for(int j = 0; j < 26; ++j)
            {
                key += to_string(temp[j]) + ",";
            }

            myMap[key].push_back(curr);
        }

        vector<vector<string>> result;

        for(auto kv: myMap)
        {
            result.push_back(kv.second);
        }

        return result;
        
    }
};
