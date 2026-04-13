class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;

        for(int i =0; i < strs.size(); ++i)
        {
            result += to_string(strs[i].length()) + "#" + strs[i];
        }

        return result;

    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        int s_size = s.length();
        int i = 0;

        while(i < s_size)
        {
            int j = i;

            while(s[j] != '#')
            {
                ++j;
                if(j >= s_size)
                {
                    break;
                }
            }

            if(j >= s_size)
            {
                break;
            }

            std::string num = s.substr(i,j-i);
            int new_length = stoi(num);
            if(new_length == 0)
            {
                result.push_back("");
                i = j + 1;
                continue;
            }

            std::string new_string = s.substr(++j, new_length);
            result.push_back(new_string);

            i = j + new_length;

        }

        return result;

    }
};
