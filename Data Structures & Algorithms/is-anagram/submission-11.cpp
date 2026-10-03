class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;

        for(char c: s)
        {
            s_map[c]++;
        }
        for(char c: t)
        {
            t_map[c]++;
        }

        for(auto kv: s_map)
        {
            char k = kv.first;
            int v = kv.second;
            if(t_map.find(k) != t_map.end())
            {
                if(v != t_map[k])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};
