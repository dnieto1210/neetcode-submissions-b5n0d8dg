class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }

        std::unordered_map<int,int> s_map;
        std::unordered_map<int,int> t_map;

        for(char c: s)
        {
            s_map[c] += 1;
        }
        for(char c: t)
        {
            t_map[c] += 1;
        }

        for(auto kv: s_map)
        {
            int key = kv.first;
            int val = kv.second;

            if(t_map.find(key) == t_map.end())
            {
                return false;
            }
            else
            {
                if(t_map[key] != val)
                {
                    return false;
                }
            }

        }

        return true;

        
    }
};
