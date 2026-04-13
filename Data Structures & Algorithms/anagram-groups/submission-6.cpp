class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> myMap;

        //group anagrams based on frequency of the string

        for(int i = 0; i < strs.size(); ++i)
        {
            std::string curr = strs[i];
            std::string count = "";
            std::vector<int> nums (26, 0);

            for(char c: curr)
            {
                nums[c - 'a']++;
            }
            for(int d : nums)
            {
                count += to_string(d) + ',';
            }
            if(myMap.find(count) != myMap.end())
            {
                myMap[count].push_back(curr);
            }
            else
            {
                myMap[count] = {curr};
            }
        }

        std::vector<std::vector<std::string>> result;
        for(auto k : myMap)
        {
            result.push_back(myMap[k.first]);
        }

        return result;
        
    }
};
