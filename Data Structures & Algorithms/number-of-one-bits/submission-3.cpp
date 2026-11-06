class Solution {
public:
    int hammingWeight(uint32_t n) {

        /*

        0001  
        0010
        0011
        0100
        0101
        0110
        0111
        1111


        */
        int one = 1;
        int count = 0;
        while(n != 0) {
            int res = one & n;
            if(res == 1){
                ++count;
            }
            n = n >> 1;
        }
        return count;

    }
};
