class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;
        int longestSub = 0;
        int maxFreq = 0;
        int start = 0;
        int end = 0;

        while(end < s.size())
        {
            freq[s[end]]++;
            maxFreq = std::max(maxFreq, freq[s[end]]);
            if(end-start+1-maxFreq > k)
            {
                freq[s[start]]--;
                ++start;
            }

            longestSub = max(longestSub, end-start+1);
            ++end;
        }

        return longestSub;
        
    }
};
