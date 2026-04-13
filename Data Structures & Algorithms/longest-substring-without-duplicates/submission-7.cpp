class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<char> mySet;
        int left = 0;
        int right = 0;
        int count = 0;

        while(right < s.length())
        {
            char c = s[right];
            while(mySet.find(c) != mySet.end())
            {
                mySet.erase(s[left]);
                ++left;
            }
            mySet.insert(s[right]);
            count = max(count, right-left+1);
            ++right;
        }

        return count;
        
    }
};
