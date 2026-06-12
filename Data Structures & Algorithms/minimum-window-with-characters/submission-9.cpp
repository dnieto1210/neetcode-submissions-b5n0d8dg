class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size())
        {
            return "";
        }

        unordered_map<char, int> myMap;
        int total_char = 0;
        for(char c : t)
        {
            myMap[c]++;
            total_char++;
        }

        int left = 0;
        int right = left;
        int minLength = INT_MAX;
        int startIdx = 0;

        while(right < s.size())
        {
            char c = s[right];
            if(myMap.find(c) != myMap.end())
            {
                myMap[c]--;
                if(myMap[c] >= 0)
                {
                    total_char--;
                }

                while(total_char == 0)
                {
                    int pot = right-left+1;
                    if(pot < minLength)
                    {
                        minLength = pot;
                        startIdx = left;
                    }

                    if(myMap.find(s[left]) != myMap.end())
                    {
                        if(myMap[s[left]] >= 0)
                        {
                            ++total_char;
                        }
                        myMap[s[left]]++;
                    }
                    ++left;
                }
            }
            ++right;
        }

        if(minLength == INT_MAX)
        {
            return "";
        }
        return s.substr(startIdx, minLength);
        
    }
};
