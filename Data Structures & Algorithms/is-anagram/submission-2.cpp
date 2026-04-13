class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }

        std::unordered_map<char, int> myMap;

        for(char c: s)
        {
            myMap[c]++;
        }

        for(char c: t)
        {
            if(myMap.find(c) != myMap.end())
            {
                myMap[c]--;
                if(myMap[c] == 0)
                {
                    myMap.erase(c);
                }
            }
            else
            {
                return false;
            }
        }

        if(myMap.size() == 0)
        {
            return true;
        }
        return false;
        
    }
};
