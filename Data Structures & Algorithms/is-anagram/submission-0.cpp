class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

    std::unordered_map<char, int> s_count;
    std::unordered_map<char, int> t_count;

    for (int i = 0; i < s.size(); i++) {
        s_count[s[i]]++;
        t_count[t[i]]++;
    }

 
    for (const std::pair<const char, int>& pair : s_count) {
        if (s_count[pair.first] != t_count[pair.first])
        {
            return false;
        }
    }
    return true;
        
    }
};
