class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        {
            return false;
        }

        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for(char& c : s)
        {
            s_map[c]++;
        }
        for(char& c : t)
        {
            t_map[c]++;
        }

        for(auto& kv: s_map)
        {
            if(t_map.find(kv.first) == t_map.end())
            {
                return false;
            }
            else
            {
                if(s_map[kv.first] != t_map[kv.first])
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};
