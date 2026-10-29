class Solution {
public:
    void dfs(int idx, string& digits, unordered_map<char, vector<char>>& myMap) {
        if(idx >= digits.size() && temp.size() > 0) {
            result.push_back(temp);
            return;
        }

        char key = digits[idx];
        for(int i = 0; i < myMap[key].size(); ++i)
        {
            char c = myMap[key][i];
            temp.push_back(c);
            dfs(idx+1, digits, myMap);
            temp.pop_back();
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        temp = "";
        unordered_map<char, vector<char>> myMap;
        myMap['2'] = {'a','b','c'};
        myMap['3']= {'d', 'e', 'f'};
        myMap['4'] = {'g', 'h', 'i'};
        myMap['5'] = {'j', 'k', 'l'};
        myMap['6'] = {'m', 'n', 'o'};
        myMap['7'] = {'p', 'q', 'r', 's'};
        myMap['8'] = {'t', 'u', 'v'};
        myMap['9'] = {'w', 'x', 'y', 'z'};
        dfs(0, digits, myMap); 
        return result;
        
    }
private:
    vector<string> result;
    string temp;
};
