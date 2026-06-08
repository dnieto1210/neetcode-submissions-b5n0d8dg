class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = left;
        unordered_map<char, int> myMap;
        int maxFreq = 0;
        int longestSub = 0;

        while(right < s.size())
        {
            char c = s[right];
            myMap[c]++;
            maxFreq = max(maxFreq, myMap[c]);
            if((right-left+1)-maxFreq <= k)
            {
                ++right;
                longestSub = max(longestSub, right-left+1);
                continue;
            }
            //otherwise we have used up our replacements
            while((right-left+1)-maxFreq > k)
            {
                myMap[s[left]]--;
                int curr_max = 0;
                for(auto kv: myMap)
                {
                    if(kv.second > curr_max)
                    {
                        curr_max = kv.second;
                    }
                }
                maxFreq = curr_max;
                ++left;
            }
            ++right;

        }

        return longestSub-1;
        
    }
};
