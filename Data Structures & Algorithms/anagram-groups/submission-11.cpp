class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<string>> myMap;

        for(int i = 0; i < strs.size(); ++i)
        {
            string curr = strs[i];

            string key = "";
            vector<int> freq(26, 0);
            for(char c : curr)
            {
                freq[c-'a']++;
            }
            for(int j = 0; j < 26; ++j)
            {
                key += to_string(freq[j]) + ',';
            }

            myMap[key].push_back(curr);
        }

        for(const auto kv: myMap)
        {
            vector<string> group = kv.second;
            result.push_back(group);
        }

        return result;
    }
};
