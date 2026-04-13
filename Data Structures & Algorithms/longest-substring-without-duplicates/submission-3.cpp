class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> myMap;
        int start = 0;
        int end = 0;
        int result = 0;

        while(end < s.length())
        {
            char c = s[end];

            while(myMap.find(c) != myMap.end())
            {
                myMap.erase(s[start]);
                ++start;
            }

            myMap[c] = 1;
            result = std::max(result, end-start+1);
            ++end;
        }

        return result;
        
    }
};
