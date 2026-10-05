class Solution {
public:

    string encode(vector<string>& strs) {

        string res = "";
        for(int i = 0; i < strs.size(); ++i)
        {
            string curr = strs[i];
            int count = curr.size();
            res += '#' + to_string(count) + '#' + curr;
        }
        return res;
    }

    vector<string> decode(string s) {

        vector<string> result;
        int left = 0;
        string count = "";
    

        while(left < s.size())
        {
            char c = s[left];
            if(c == '#' && count == "")
            {
                ++left;
                while(s[left] != '#')
                {
                    count += s[left];
                    ++left;
                }
            }
            else if(c == '#' && count != "")
            {
                ++left;
                string word = s.substr(left, stoi(count));
                left = left + stoi(count);
                count = "";
                result.push_back(word);
            }
        }

        return result;
    }
};
