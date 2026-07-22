class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
        {
            return false;
        }

        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);

        for(char c: s1)
        {
            s1Map[c - 'a']++;
        }
    
        for(int i = 0; i < s1.size(); ++i)
        {
            char c = s2[i];
            s2Map[c-'a']++;
        }

        if(s1Map == s2Map)
        {
            return true;
        }

        int left = 0;
        for(int i = s1.size(); i < s2.size(); ++i)
        {
            char rem = s2[left];
            char c = s2[i];
            
            s2Map[rem - 'a']--;
            ++left;
            s2Map[c - 'a']++;
            if(s2Map == s1Map)
            {
                return true;
            }
        }

        return false;
        
    }
};
