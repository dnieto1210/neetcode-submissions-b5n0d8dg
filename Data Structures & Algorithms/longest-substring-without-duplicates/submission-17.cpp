class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        unordered_map<char, int> myMap;
        int longest = 0;

        while(right < s.size())
        {
            char c = s[right];
            if(myMap.find(c) != myMap.end() && myMap[c] >= left && myMap[c] < right)
            {
                left = myMap[c] + 1;
            }

            myMap[c] = right;
            longest = max(longest, right-left+1);
            ++right;
        }

        return longest;
        
    }
};
