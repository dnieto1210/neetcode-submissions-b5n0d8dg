class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxf = 0;
        int result = 0;

        unordered_map<char, int> myMap;

        while(right < s.size())
        {
            myMap[s[right]]++;
            maxf = max(maxf, myMap[s[right]]);
            while(right-left+1-maxf > k)
            {
                myMap[s[left]]--;
                ++left;
            }

            result = max(result, right-left+1);
            ++right;

        }
        return result;
        
    }
};
