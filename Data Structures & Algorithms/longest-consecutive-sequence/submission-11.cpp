class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        unordered_set<int> mySet;
        int maxLen = 0;
        for(int n: nums)
        {
            mySet.insert(n);
        }

        for(int n: nums)
        {
            if(mySet.find(n-1) == mySet.end())
            {
                int pot = 0;
                int trav = n;
                while(mySet.find(trav) != mySet.end())
                {
                    ++pot;
                    ++trav;
                }

                maxLen = max(maxLen, pot);
            }
        }

        return maxLen;
    }
};
