class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())
        {
            return false;
        }
        std::unordered_map<char, int> s1_map;
        std::unordered_map<char, int> s2_map;

        for(char c: s1)
        {
            s1_map[c]++;
        }

        int left = 0;
        int right = 0;
        int need = s1_map.size();
        int have = 0;

        while(right < s2.length())
        {
            char c = s2[right];
            s2_map[c]++;
            if(s1_map.count(c) && s1_map[c] == s2_map[c])
            {
                ++have;
            }

            if(right - left + 1 > s1.length())
            {
                char k = s2[left];
                if(s1_map.count(k) && s1_map[k] == s2_map[k])
                {
                    --have;
                }
                s2_map[k]--;

                if(s2_map[k] == 0)
                {
                    s2_map.erase(k);
                }
                ++left;
            }

            if(have == need)
            {
                return true;
            }
            ++right;

        }
        

        return false;

        
    }
};
