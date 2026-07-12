class Solution {
public:

    string encode(vector<string>& strs) {

        string result = "";
        for(int i = 0; i < strs.size(); ++i)
        {
            string curr = strs[i];
            int curr_size = curr.size();

            result += to_string(curr_size) + '#' + curr;
        }

        return result;

    }

    vector<string> decode(string s) {

        int i = 0;
        vector<string> result;
        while(i < s.size())
        {
            string size = "";
            int j = i; 
            while(s[j] != '#' && j < s.size())
            {
                size += s[j];
                ++j;
            }

            if(j >= s.size())
            {
                break;
            }
            int s_size = stoi(size);
            string curr = s.substr(j + 1, s_size);
            i = j + s_size + 1;
            result.push_back(curr);
        }

        return result;

    }
};
