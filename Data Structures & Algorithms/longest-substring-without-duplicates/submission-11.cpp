class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = left;
        unordered_set<char> mySet;
        int longestLength = 0;

        while(right < s.size())
        {
            char c = s[right];
            if(mySet.find(c) != mySet.end())
            {
                while(mySet.find(c) != mySet.end())
                {
                    mySet.erase(s[left]);
                    ++left;
                }
            }
            mySet.insert(c);
            longestLength = max(longestLength, right-left+1);
            ++right;
        }

        return longestLength;
        
    }
};
