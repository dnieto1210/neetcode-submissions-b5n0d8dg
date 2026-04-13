class Solution {
public:
    bool anagram(string s, string t)
    {
        if(s.length() != t.length())
        {
            return false;
        }

        std::unordered_map<int, int> s_map;
        std::unordered_map<int,int> t_map;
        for(int i = 0; i < s.length(); ++i)
        {
            s_map[s[i]] += 1;
            t_map[t[i]] += 1;
        }

        return s_map == t_map;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,int> group;
        vector<vector<string>> result;

        for(int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            if(group.find(s) != group.end())
            {
                //already in a group 
                continue;
            }
            std::vector<string> sub;
            sub.push_back(s);
            group[s] = 1;
            for(int j = i+1; j < strs.size(); ++j)
            {
                string t = strs[j];
                bool an = anagram(s,t);
                if(an)
                {
                    sub.push_back(t);
                    group[t] = 1;
                }
            }
            result.push_back(sub);

        }

        return result;
        
    }
};
