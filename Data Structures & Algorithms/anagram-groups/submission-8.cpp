class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> myMap;

        for(int i = 0; i < strs.size(); ++i)
        {
            std::string s = strs[i];
            std::string key = "";
            std::vector<int> check(26, 0);

            for(char c : s)
            {
                check[c- 'a']++;
            }

            for(int i = 0; i < 26; ++i)
            {
                key += to_string(check[i]) + ',';
            }

            myMap[key].push_back(s);

            /*
            if(myMap.find(key) != myMap.end())
            {
                myMap[key].push_back(s);
            }
            else
            {
                std::vector<std::string> value;
                value.push_back(s);
                myMap[key] = value;
            }
            */
        }

        std::vector<std::vector<std::string>> result;

        for(auto kv : myMap)
        {
            result.push_back(kv.second);
        }

        return result;
        
    }
};
