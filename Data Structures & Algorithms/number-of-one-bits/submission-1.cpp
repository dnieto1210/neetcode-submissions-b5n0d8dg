class Solution {
public:
    int hammingWeight(uint32_t n) {
        


        if(n == 0)
        {
            return 0;
        }
        else
        {
            int counter = 0;
            while(n != 0)
            {
                int temp = n & 1;
                if(temp == 1)
                {
                    ++counter;
                }
                n = n >> 1;
            }
            return counter;
        }

    }
};
