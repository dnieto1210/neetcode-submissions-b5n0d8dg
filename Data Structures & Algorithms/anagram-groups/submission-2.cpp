class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<std::string>> myMap;
        std::vector<std::vector<std::string>> result;

        for(std::string s : strs)
        {
            std::vector<int> myVector(26);

            for(const char c: s)
            {
                myVector[c - 'a']++;
            }

            std::string key;

            for(int i : myVector)
            {
                key += to_string(i) + '#';
            }

            myMap[key].push_back(s);
        }

        for(const auto& pair: myMap)
        {
            result.push_back(pair.second);
        }
        return result;
        
    }
};
