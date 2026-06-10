class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
        {
            return false;
        }

        unordered_map<char, int> myMap;
        for(char c : s1)
        {
            myMap[c]++;
        }

        int left = 0;
        int right = left;
        while(right < s2.size())
        {
            char c = s2[right];
            if(myMap.find(c) == myMap.end())
            {

                while(left < right)
                {
                    char beg = s2[left];
                    if(myMap.find(beg) != myMap.end())
                    {
                        myMap[beg]++;
                    }
                    ++left;
                }
                ++right;
                left = right;
            }
            else
            {
                //char is in our map
                myMap[c]--;
                if(myMap[c] > 0)
                {
                    ++right;
                }
                else if(myMap[c] == 0)
                {
                    //check if everything is 0
                    //O(26) because we only working with lower case letters
                    bool all_zero = true;
                    for(auto kv: myMap)
                    {
                        if(kv.second != 0)
                        {
                            all_zero = false;
                        }
                    }
                    if(all_zero)
                    {
                        return true;
                    }
                    ++right;
                }
                else
                {
                    //it is less than 0 which means we have a char that occurs more than it occurs in original string
                    while(myMap[c] < 0)
                    {
                        char beg = s2[left];
                        myMap[beg]++;
                        ++left;
                    }
                    ++right;
                }
            }

        }

        return false;
        
    }
};
