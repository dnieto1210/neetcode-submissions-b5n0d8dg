class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
        {
            return false;
        }

        std::unordered_map<char,int> freq;
        std::unordered_map<char,int> actual;
        for(int i = 0; i < 26; ++i)
        {
            actual['a'+i] = 0;
            freq['a' + i] = 0;
        }
        for(char& c : s1)
        {
            actual[c]++;
        }

        int size = s1.size();
        for(int i = 0;  i < size; ++i)
        {
            freq[s2[i]]++;
        }
        if(freq == actual)
        {
            return true;
        }

        int left = 0;
        int right = size-1;

        for(int i = size; i < s2.size(); ++i)
        {
            right = i;
            freq[s2[right]]++;
            freq[s2[left]]--;
            ++left;
            if(freq == actual)
            {
                return true;
            }

        }

        return false;
        
    }
};
