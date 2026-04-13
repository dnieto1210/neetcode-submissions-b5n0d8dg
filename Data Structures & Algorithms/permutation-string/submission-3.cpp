class Solution {
public:
    //fixed size window
    bool checkInclusion(string s1, string s2) {
        std::vector<int>need (26,0);
        std::vector<int>want (26,0);

        for(char c : s1)
        {
            need[c - 'a']++;
        }

        int window = s1.size();
        for(int i = 0; i < s2.size(); ++i)
        {
            char c = s2[i];
            want[c - 'a']++;
            if(i >= window)
            {
                want[s2[i-window]- 'a']--;
            }

            if(want == need)
            {
                return true;
            }
        }

        return false;
        
    }
};
