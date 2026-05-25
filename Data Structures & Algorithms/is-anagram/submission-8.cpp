class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

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
            char key = kv.first;
            int val = kv.second;
            if(t_map.find(key) == t_map.end())
            {
                return false;
            }
            else
            {
                if(t_map[key] != s_map[key])
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};
