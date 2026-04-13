class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        std::unordered_map<char,int> s_map;
        std::unordered_map<char, int> t_map;

        for(char c : s)
        {
            s_map[c]++;
        }
        for(char c : t)
        {
            t_map[c]++;
        }

        for(auto k : s_map)
        {
            if(t_map.find(k.first) == t_map.end())
            {
                return false;
            }
            else
            {
                if(t_map[k.first] != s_map[k.first])
                {
                    return false;
                }
            }
        }


        return true;
    }
};
