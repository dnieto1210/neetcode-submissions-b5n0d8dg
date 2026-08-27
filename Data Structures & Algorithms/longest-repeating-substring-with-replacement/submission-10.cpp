class Solution {
public:
    int characterReplacement(string s, int k) {


        vector<int> freq(26, 0);
        int left = 0;
        int right = 0;
        int maxElement = 0;
        int longest = 0;
        while(right < s.size())
        {
            char c = s[right];
            int f = freq[c - 'A'];
            freq[c - 'A'] = f + 1;
            maxElement = max(maxElement, freq[c-'A']);
            while((right - left + 1) - maxElement > k)
            {
                freq[s[left] - 'A']--;
                maxElement = -1;
                for(int i = 0; i < 26; ++i)
                {
                    maxElement = max(maxElement, freq[i]);
                }
                ++left;
            }

            longest = max(longest, right-left+1);
            ++right;
        }

        return longest;
    }
};
