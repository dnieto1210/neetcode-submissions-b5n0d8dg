class Solution {
public:

    string encode(vector<string>& strs) {

        string result = "";

        for(int i = 0; i < strs.size(); ++i)
        {
            result += to_string(strs[i].size()) + "#" + strs[i];
        }

        return result;

    }

    vector<string> decode(string s) {

        int len = s.size();
        int i = 0;
        vector<string> result;

        while(i < len)
        {
            int num = i;
            string temp = "";
            while(s[num] != '#')
            {
                temp += s[num];
                ++num;
            }
            ++num;

            //go to 
            int str_len = stoi(temp);
            int j = 0;
            string str = "";
            while(j < str_len)
            {
                str += s[num];
                ++num;
                ++j;
            }

            //str is done so push it to the vector
            result.push_back(str);
            i = num;
        }
        return result;

    }
};
