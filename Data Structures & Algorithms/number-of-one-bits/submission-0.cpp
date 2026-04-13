class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int check = 1;

        for(int i = 0; i < 32; ++i)
        {
            int res = check & n;
            if(res == 1)
            {
                ++count;
            }
            n = n >> 1;
        }

        return count;

    }
};
