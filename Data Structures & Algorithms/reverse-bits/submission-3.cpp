class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int i = 0;
        uint32_t res = 0;
        while(i < 32) {
            uint32_t check = n & 1;
            res = res | check;
            if(i == 31) {
                break;

            }
            res = res << 1;
            n = n >> 1;
            ++i;
        }
        return res;
        
    }
};
