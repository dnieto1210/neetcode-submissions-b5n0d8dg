class Solution {
public:

    string encode(vector<string>& strs) {
        string en = "";
        for(string s : strs)
        {
            en += to_string(s.length()) + '#' + s;
        }
        return en;
    }

    vector<string> decode(string s) {

        int left = 0;
        int right = left;
        vector<string> result;

        while(left < s.length())
        {
            string num = "";
            while(s[right] != '#')
            {
                num += s[right];
                ++right;
            }

            int size = stoi(num);
            right = right+1;
            string str = "";
            while(size > 0)
            {
                str += s[right];
                ++right;
                --size;
            }

            result.push_back(str);
            left = right;
        }

        return result;



    }
};
