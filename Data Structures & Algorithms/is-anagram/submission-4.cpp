class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
        {
            return false;
        }

        //otherwise same length and potentially anagrams

        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;

        for(int i = 0; i < s.length(); ++i)
        {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }

        for(auto k : sMap)
        {
            if(tMap.find(k.first) == tMap.end())
            {
                return false;
            }
            if(tMap[k.first] != sMap[k.first])
            {
                return false;

            }
        }

        return true;
        
    }
};
