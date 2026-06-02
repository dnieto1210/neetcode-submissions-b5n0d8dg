class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs.size(); ++i)
        {
            int amount = strs[i].size();
            result += to_string(amount) + "#" +  strs[i];

        }
        return result;

    }

    vector<string> decode(string s) {

        int i = 0;
        vector<string> result;
        while(i < s.size())
        {
            string size = "";
            int check = i;
            while(s[check] != '#')
            {
                size += s[check];
                ++check;
            }
            //check is pointing at #
            int amount = stoi(size);
            string curr = s.substr(++check, amount);
            result.push_back(curr);
            i = check + amount;
        }

        return result;

    }
};
