class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(char c : s)
        {
            s_map[c]++;
        }
        for(char c : t)
        {
            t_map[c]++;
        }

        for(const auto kv : s_map)
        {
            char c = kv.first;
            int amount = kv.second;
            if(t_map.find(c) == t_map.end())
            {
                return false;
            }
            else
            {
                if(t_map[c] != amount)
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};
