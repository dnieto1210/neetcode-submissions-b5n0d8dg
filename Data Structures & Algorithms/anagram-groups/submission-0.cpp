class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort the string 
        std::unordered_map<std::string, std::vector<string>> anagrams;
        for(const std::string& s: strs)
        {
            std::string mix = s;
            sort(mix.begin(), mix.end());
            anagrams[mix].push_back(s);
        }

        std::vector<std::vector<string>> result;

        for(const auto& pair: anagrams)
        {
            result.push_back(pair.second);

        }

        return result;

        
    }

    
};
