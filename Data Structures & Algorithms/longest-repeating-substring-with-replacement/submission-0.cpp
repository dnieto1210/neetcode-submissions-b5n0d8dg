class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int result = 0;
        std::unordered_map<char, int> myMap;
        int max_frequency = 0;

        while(right < s.length())
        {
            myMap[s[right]]++;
            max_frequency = std::max(max_frequency, myMap[s[right]]);

            while((right - left + 1)-max_frequency > k)
            {
                myMap[s[left]]--;
                ++left;
            }
            result = std::max(result, right- left + 1);
            ++right;

        }
        return result;
    }
};
