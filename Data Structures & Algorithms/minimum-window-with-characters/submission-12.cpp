class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size())
        {
            return "";
        }

        unordered_map<char, int> tMap;
        int length = INT_MAX;
        int start_idx = 0;

        for(char c: t)
        {
            tMap[c]++;
        }

        int left = 0;
        int right = 0;

        while(right < s.size())
        {
            char c = s[right];

            if(tMap.find(c) != tMap.end())
            {
                tMap[c]--;
                if(tMap[c] <= 0)
                {
                    //check if everything is less
                    bool zero = true;
                    for(auto kv: tMap)
                    {
                        if(kv.second > 0)
                        {
                            zero = false;
                            break;
                        }
                    }

                    if(zero)
                    {
                        //we have all chars in t so lets see how left we can go
                        while(left <= right)
                        {
                            if(right-left+1 < length)
                            {
                                length = right-left+1;
                                start_idx = left;
                            }

                            char check = s[left];
                            if(tMap.find(check) != tMap.end())
                            {
                                tMap[check]++;
                                if(tMap[check] <=  0)
                                {
                                    ++left;
                                }
                                else
                                {
                                    ++left;
                                    break;
                                }

                            }
                            else
                            {
                                ++left;
                            }
                        }

                        
                    }
                    else
                    {
                        //just keep going right;
                    }
                }

            }
            ++right;
        }

        return (length == INT_MAX) ? "" : s.substr(start_idx, length);
        
    }
};
