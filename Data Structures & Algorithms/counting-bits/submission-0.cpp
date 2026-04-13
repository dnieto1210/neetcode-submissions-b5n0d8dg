class Solution {
public:
    int numOnes(int n)
    {
        int count = 0;
        while(n != 0)
        {
            int t = 1;
            int k = n & t;
            if(k == 1)
            {
                ++count;
            }
            n = n >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {

        vector<int> result;
        for(int i = 0; i <= n; ++i)
        {
            int val = numOnes(i);
            result.push_back(val);
        }

        return result;
        
    }
};
