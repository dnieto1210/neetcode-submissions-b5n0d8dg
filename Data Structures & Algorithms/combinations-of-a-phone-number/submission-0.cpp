class Solution {
public:
    void backtrack(vector<string>& result, unordered_map<char, vector<char>>& myMap, string s, string word, int i)
    {
        if(i == word.length() && i > 0)
        {
            result.push_back(s);
            return;
        }

        vector<char> vec = myMap[word[i]];
        for(int j = 0; j < vec.size(); ++j)
        {
            s += vec[j];
            backtrack(result, myMap, s, word, i + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<char, vector<char>> myMap;
        myMap['2'] = {'a','b','c'};
        myMap['3'] = {'d','e','f'};
        myMap['4'] = {'g', 'h', 'i'};
        myMap['5'] = {'j', 'k', 'l'};
        myMap['6']= {'m', 'n', 'o'};
        myMap['7']= {'p', 'q', 'r', 's'};
        myMap['8']= {'t', 'u', 'v'};
        myMap['9'] = {'w', 'x', 'y', 'z'};

        string s = "";

        backtrack(result, myMap, s, digits, 0);

        return result;

        
    }
};
