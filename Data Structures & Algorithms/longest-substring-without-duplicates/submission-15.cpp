class Solution {
public:
    int lengthOfLongestSubstring(string s) {


        int left = 0;
        int right = 0;
        int longest = 0;
        unordered_set<char> mySet;

        while(right < s.size())
        {
            char c = s[right];
            if(mySet.find(c) != mySet.end())
            {
                //we have a duplicate char
                while(s[left] != c) //maybe left < right
                {
                    mySet.erase(s[left]);
                    ++left;
                }
                mySet.erase(s[left]);
                ++left;
            }

            mySet.insert(c);
            longest = max(longest, right-left+1);
            ++right;
        }

        return longest;


        
    }
};
