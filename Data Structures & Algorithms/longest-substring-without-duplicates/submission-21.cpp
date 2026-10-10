class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //unordered_map<char,int> myMap;
        int longest = 0;
        unordered_set<char> mySet;
        
        int left = 0;
        int right = left;
        while(right < s.size())
        {
            char c = s[right];
            while(mySet.find(c) != mySet.end())
            {
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
