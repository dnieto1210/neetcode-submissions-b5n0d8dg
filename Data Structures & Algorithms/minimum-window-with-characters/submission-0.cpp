class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> s_map, t_map;

        for(char c : t)
        {
            t_map[c]++;
        }

        int need = t_map.size();
        int have = 0;
        std::string result = "";
        int result_size = INT_MAX;

        int left = 0;
        int right = 0;

        while(right < s.size())
        {
            char c = s[right];
            s_map[c]++;

            if(t_map.count(c) && s_map[c] == t_map[c])
            {
                ++have;
            }

            while(have == need)
            {
                if(right - left + 1 < result_size)
                {
                    result_size = right - left + 1;
                    result = s.substr(left, right-left+1);
                }

                char k = s[left];

                if(t_map.count(k) && t_map[k] == s_map[k])
                {
                    --have;
                }

                s_map[k]--;
                if(s_map[k] == 0)
                {
                    s_map.erase(k);
                }

                ++left;
            }

            ++right;
        }

        return result;
        
    }
};
