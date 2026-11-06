class Solution {
public:
    int numBits(int n) {
        int count = 0;
        while(n != 0) {
            int res = n & 1;
            if(res == 1) {
                ++count;
            }
            n = n >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {

        vector<int> result;
        for(int i = 0; i <= n; ++i) {
            int res = numBits(i);
            result.push_back(res);
        }
        return result;
        
    }
};
