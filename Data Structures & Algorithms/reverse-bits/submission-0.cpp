class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int reverse = 0;
        for(int i = 0; i < 32; ++i)
        {
            int move = n & 1;
            n = n >> 1;
            reverse = reverse | move;
            if(i == 31)
            {
                break;
            }
            reverse = reverse << 1;
        }

        return reverse;
        
    }
};
