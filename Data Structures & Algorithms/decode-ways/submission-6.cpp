class Solution {
public:
    int numDecodings(string s) {

        unordered_set<string> mySet;
        vector<int> result(s.size()+2, 0);
        int n = s.size();
        for(int i = 1; i < 27; ++i)
        {
            string a = to_string(i);
            mySet.insert(a);
        }

        for(int i = n-1; i >= 0; --i)
        {
            string one = s.substr(i, 1);
            string two = (i + 1 >= s.size()) ? "" : s.substr(i, 2);

            if(one == "0")
            {
                continue;
            }
            else if(i == n-1 && (mySet.find(one) != mySet.end()))
            {
                result[i] = 1;
            }
            else if(i == n-2)
            {
                if(mySet.find(two) != mySet.end())
                {
                    result[i] = 1+ result[i+1];
                }
                else
                {
                    result[i] = result[i+1];
                }
            }
            else
            {
                if(mySet.find(two) != mySet.end() && mySet.find(one) != mySet.end())
                {
                    result[i] = result[i+1] + result[i+2];
                }
                else if(mySet.find(two) == mySet.end())
                {
                    result[i] = result[i+1];

                }
            }

        }
        return result[0];
    }
};
