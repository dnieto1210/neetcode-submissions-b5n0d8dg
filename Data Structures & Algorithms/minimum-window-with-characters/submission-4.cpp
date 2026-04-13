class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size())
        {
            return "";
        }

        int shortest_length = INT_MAX;
        std::string shortest = "";
        int left = 0;
        int right = 0;
        int total_char = 0;
        std::unordered_map<char, int> myMap;
        for(char c : t)
        {
            myMap[c]++;
            total_char++;
        }

        while(right < s.size())
        {
            char c = s[right];
            if(myMap.find(c) != myMap.end())
            {
                myMap[c]--;
                if(myMap[c] >= 0)
                {
                    total_char--;
                }
                else
                {
                    //not sure

                }

                if(total_char == 0)
                {
                    /*
                    if(right-left+1 < shortest_length)
                    {
                        longest = s.substr(left, right-left+1);
                        shortest_length = right-left+1;
                    }
                    */

                    //remove from the front
                    while(total_char == 0)
                    {
                        if(right-left+1 < shortest_length)
                        {
                            shortest = s.substr(left, right-left+1);
                            shortest_length = right-left+1;
                        }
                        if(myMap.find(s[left]) != myMap.end())
                        {
                            myMap[s[left]]++;
                            if(myMap[s[left]] > 0)
                            {
                                total_char++;
                            }
                        }
                        left++;

                    }

                }
            }
            ++right;

        }


        return shortest;
        
    }
};
