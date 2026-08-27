class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
        {
            return false;
        }

        vector<int> s1_map(26, 0);
        vector<int> s2_map(26,0);

        for(char c : s1)
        {
            s1_map[c - 'a']++;
        }
        for(int i = 0; i < s1.size(); ++i)
        {
            char c = s2[i];
            s2_map[c-'a']++;
        }
        if(s1_map == s2_map)
        {
            return true;
        }

        int left = 0;
        for(int i = s1.size(); i < s2.size(); ++i)
        {
            char c = s2[i];
            s2_map[s2[left]-'a']--;
            ++left;
            s2_map[c - 'a']++;
            if(s2_map == s1_map)
            {
                return true;
            }
        }

        return false;
    }
};
