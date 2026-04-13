class Solution {
public:
    bool isPalindrome(string s) {

        int start = 0;
        int end = s.length()-1;

        while(start <= end)
        {
            if(!std::isalnum(s[start]))
            {
                start++;
                continue;
            }

            if(!std::isalnum(s[end]))
            {
                end--;
                continue;
            }

            //otherwise they are valid chars

            if(std::tolower(s[start]) != std::tolower(s[end]))
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
        
    }
};
