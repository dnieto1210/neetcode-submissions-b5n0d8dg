class Solution {
public:


    void backtrack(string& digits, vector<string>& result, string& check, int idx, unordered_map<char, vector<char>>& letters)
    {
        if(check.size() == digits.size())
        {
            result.push_back(check);
            return;
        }

        char dig = digits[idx];
        
        for(int i = 0; i < letters[dig].size(); ++i)
        {
            check.push_back(letters[dig][i]);
            backtrack(digits, result, check, idx+1, letters);
            check.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }

        unordered_map<char, vector<char>> letters;
        letters['2'] = {'a','b','c'};
        letters['3'] = {'d','e','f'};
        letters['4'] = {'g','h','i'};
        letters['5'] = {'j','k','l'};
        letters['6'] = {'m','n','o'};
        letters['7'] = {'p','q','r','s'};
        letters['8'] = {'t','u','v'};
        letters['9'] = {'w','x','y','z'};

        vector<string> result;
        string check = "";
        backtrack(digits, result, check, 0, letters);
        return result;
    }
};
