class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        unordered_set<char> mySet;
        mySet.insert(s[0]);

        int left = 0;
        int right = 1;
        int longest = 1;

        while(right < s.length())
        {
            char a = s[right];
            if(mySet.find(a) != mySet.end())
            {
                mySet.erase(s[left]);
                ++left;
            }
            else
            {
                int pot = right - left + 1;
                longest = max(pot, longest);
                ++right;
                mySet.insert(a);

            }

        }

        return longest;

        
    }
};
