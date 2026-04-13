class Solution {
public:
    bool isAnagram(string s, string t) {

        int s_size = s.length();
        int t_size = t.length();

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
        for(char c : t)
        {
            t_map[c]++;
        }

        for(auto kv : s_map)
        {
            if(kv.second != t_map[kv.first])
            {
                return false;
            }
        }

        return true;


        
    }
};
