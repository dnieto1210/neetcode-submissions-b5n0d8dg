class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        
        unordered_set<string> mySet;
        int largest = INT_MIN;
        for(string& temp : wordDict)
        {
            if(temp.size() > largest)
            {
                largest = temp.size();
            }
            mySet.insert(temp);
        }
        vector<int> result(s.size()+1, 0);
        result[s.size()]= 1;
        

        for(int i = s.size()-1; i >= 0; --i)
        {
            int len = s.size() - i;
            int pot = 0; 
            for(const string& a : mySet)
            {
                string t = "";
                if(a.size() <= len)
                {
                    t = s.substr(i, a.size());
                    if(t == a)
                    {
                        if(i + a.size() >= s.size())
                        {
                            pot = 1;
                        }
                        else
                        {
                            pot = max(result[i + a.size()], pot);
                        }
                    }

                }
                else
                {
                    continue;
                }
            }
            result[i] = pot;
        }

        return (result[0] == 1) ? true : false;
        
    }
};
