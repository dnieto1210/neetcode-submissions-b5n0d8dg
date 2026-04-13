class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;

        while(left < right)
        {
            while(!isalnum(s[right]) && left < right)
            {
                --right;
            }
            while(!isalnum(s[left]) && right > left)
            {
                ++left;
            }

            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
        
    }
};
