class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = left;
        int longest = 0;
        int mostFreq = 0;
        unordered_map<char,int> myMap;

        while(right < s.size())
        {
            char c = s[right];
            myMap[c]++;
            mostFreq = max(mostFreq, myMap[c]);
            while((right-left+1)-mostFreq  > k)
            {
                myMap[s[left]]--;
                ++left;
                mostFreq= 0;
                for(auto kv: myMap)
                {
                    char key = kv.first;
                    int val = kv.second;
                    mostFreq = max(kv.second, mostFreq);
                }
            }
            longest = max(longest, right-left+1);
            ++right;
        }
        return longest;
    }
};
