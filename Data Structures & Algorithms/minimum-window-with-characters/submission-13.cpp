class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> myMap;
        for(char c : t)
        {
            myMap[c]++;
        }

        int left = 0;
        int right = left;
        int bestIdx = -1;
        int bestLength = INT_MAX;
        while(right < s.size())
        {
            char c = s[right];
            if(myMap.find(c) != myMap.end())
            {
                //char matches char from t
                myMap[c]--;
                if(myMap[c] <= 0)
                {
                    //check if all chars are less than zero
                    bool allZeros = true;
                    for(auto kv: myMap)
                    {
                        if(kv.second > 0)
                        {
                            allZeros = false;
                            break;
                        }
                    }

                    while(allZeros)
                    {
                        //try to shorten the string as much as possible
                        if(right-left+1 < bestLength)
                        {
                            bestLength = right-left+1;
                            bestIdx = left;
                        }
                        if(myMap.find(s[left]) != myMap.end())
                        {
                            myMap[s[left]]++;
                        }
                        ++left;
                        //check allZeros
                        for(auto kv: myMap)
                        {
                            if(kv.second > 0)
                            {
                                allZeros =false;
                                break;
                            }
                        }
                    }

                }
            }
            ++right;
        }

        if(bestIdx == -1)
        {
            return "";
        }
        return s.substr(bestIdx, bestLength);
        
    }
};
