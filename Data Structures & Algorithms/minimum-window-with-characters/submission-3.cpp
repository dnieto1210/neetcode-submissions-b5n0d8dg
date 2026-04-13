class Solution {
public:
    string minWindow(string s, string t) {

        int shortest = INT_MAX;
        string result = "";
        int left = 0;
        int right = 0;

        std::unordered_map<char, int> count;
        int amount = 0;
        for(char c : t)
        {
            count[c]++;
            amount++;
        }

        while(right < s.size())
        {
            char c = s[right];
            if(count.count(c))
            {
                if(count[c] > 0)
                {
                    --amount;
                }
                --count[c];
            }
            while(amount == 0)
            {
                if(right-left+ 1 < shortest)
                {
                    shortest = right-left+1;
                    result = s.substr(left, right-left+1);
                }
                if(count.count(s[left]))
                {
                    if(count[s[left]] < 0)
                    {
                        ++count[s[left]];
                    }
                    else
                    {
                        ++count[s[left]];
                        ++amount;
                    }
                }
                ++left;
            }
            ++right;
        }

        return result;
        
    }
};
