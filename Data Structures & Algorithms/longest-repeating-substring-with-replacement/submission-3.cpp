class Solution {
public:
    int characterReplacement(string s, int k) {

        std::unordered_map<char, int> myMap;
        int left = 0;
        int right = 0;
        int longest = 0;
        int max_freq = 0;

        while(right < s.size())
        {
            char c = s[right];
            myMap[c]++;
            max_freq = std::max(max_freq, myMap[c]);

            if(right-left+1-max_freq <= k)
            {
                longest = std::max(longest, right-left+1);
            }
            else
            {
                //we have used up all our replacements so we need to shift left upwards
                myMap[s[left]]--;
                ++left;
                longest = std::max(longest, right-left+1);
            }

            ++right;

        }

        return longest;
    }
};
