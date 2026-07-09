class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int s_size = s.size();
        int t_size = t.size();
        if(s_size != t_size)
        {
            return false;
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(char c : s)
        {
            s_map[c]++;
        }

        for(char c: t)
        {
            t_map[c]++;
        }

        for(auto kv: s_map)
        {
            char c = kv.first;
            int count = kv.second;

            if(t_map.find(c) == t_map.end())
            {
                return false;
            }
            else
            {
                if(t_map[c] != count)
                {
                    return false;
                }
            }
        }

        return true;
        
    }
};
