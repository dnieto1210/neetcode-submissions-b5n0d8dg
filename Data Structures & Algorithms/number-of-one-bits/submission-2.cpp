class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0)
        {
            uint32_t one = 1;
            uint32_t check = n & 1;
            if(check == 1)
            {
                ++count;
            }
            n = n >> 1;
        }

        return count;

    }
};
