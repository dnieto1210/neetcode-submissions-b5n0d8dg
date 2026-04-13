class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> myMap;
        std::vector<std::vector<std::string>> result;

        for(int i = 0; i < strs.size(); ++i)
        {
            string curr = strs[i];
            vector<int> chrs(26,0);
            for(int j = 0; j < curr.length(); ++j)
            {
                int idx = curr[j] - 'a';
                chrs[idx] = chrs[idx] + 1;
            }

            string key = "";

            for(int z = 0; z < 26; ++z)
            {
                string c = to_string(chrs[z]);
                key += c + ",";
            }

            if(myMap.find(key) != myMap.end())
            {
                myMap[key].push_back(curr);
            }
            else
            {
                vector<string> t;
                t.push_back(curr);
                myMap[key] = t;
            }


        }

        for(auto kv : myMap)
        {
            result.push_back(kv.second);
        }



        return result;
        
    }
};
