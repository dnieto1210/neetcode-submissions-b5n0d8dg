class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = 0;
        int longest = 0;
        unordered_map<char, int> myMap;
        int max_char = INT_MIN;

        while(right < s.size())
        {
            char c = s[right];
            myMap[c]++;
            int size = right - left + 1;
            int amount = myMap[c];
            max_char = max(max_char, amount);
            if(size-max_char > k)
            {
                myMap[s[left]]--;
                ++left;
                int temp = INT_MIN;
                for(auto kv: myMap)
                {
                    temp = max(temp, kv.second);
                }
                max_char = temp;
            }
            longest = max(longest, right-left+1);
            ++right;
        }

        return longest;
        
    }
};
