class Solution {
public:

    string encode(vector<string>& strs) {

        string res = "";
        for(string s: strs)
        {
            int size = s.size();
            res += '#' + to_string(size) + '#' + s;
        }

        return res;
    }

    string helper(string s, int& t)
    {
        //first letter will be #
        //we want to get the size of the string
        ++t;
        string num = "";
        while(s[t] != '#')
        {
            num += s[t];
            ++t;
        }

        //now t is pointing at #
        int size = stoi(num);
        ++t;
        string res = s.substr(t, size);
        t = t + size;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int traverse = 0;
        while(traverse < s.size())
        {
            string curr = helper(s, traverse);
            res.push_back(curr);
        }

        return res;
    }
};
