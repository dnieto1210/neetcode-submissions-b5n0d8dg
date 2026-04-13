class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> myMap;

        for(string s: strs)
        {
            vector<int> counts(26,0);
            for(char c: s)
            {
                counts[c - 'a'] += 1;
            }
            string res;
            for(int i : counts)
            {
                res += to_string(i) + ',';
            }

            myMap[res].push_back(s);
        }

        vector<vector<string>> result;
        for(auto kv : myMap)
        {
            result.push_back(kv.second);
        }
        return result;
        
    }
};
