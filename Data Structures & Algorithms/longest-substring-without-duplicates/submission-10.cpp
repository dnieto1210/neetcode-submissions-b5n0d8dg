class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = left;
        int longest = 0;
        unordered_map<char, int> myMap;

        while(right < s.size())
        {
            char c = s[right];
            if(myMap.find(c) != myMap.end())
            {
                int idx = myMap[c];
                if(idx < left)
                {
                    myMap[c] = right;
                    longest = max(longest, right-left+1);
                    ++right;
                }
                else
                {
                    left = myMap[c] + 1;
                    myMap[c] = right;
                    longest = max(longest, right-left+1);
                    ++right;
                }

            }
            else
            {
                //it is not in our hash map so it is unique
                myMap[c] = right;
                longest = max(longest, right-left+1);
                ++right;
            }

        }
        return longest;
        
    }
};
