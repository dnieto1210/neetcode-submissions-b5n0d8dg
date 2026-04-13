class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_set<char> mySet;
        int left = 0;
        int right = 0;
        int max_length = 0;

        while(right < s.size())
        {
            char c = s[right];
            if(mySet.find(c) != mySet.end())
            {
                //char is already in a subtring
                while(mySet.find(c) != mySet.end())
                {
                    mySet.erase(s[left]);
                    ++left;
                }
                mySet.insert(c);
                max_length = std::max(max_length, right-left+1);
            }
            else
            {
                mySet.insert(c);
                max_length = std::max(max_length, right-left+1);
            }
            ++right;
        }

        return max_length;
        
    }
};
