class Solution {
public:
    int climbStairs(int n) {

        vector<int> result(n+1, -1);

        for(int i = 0; i < result.size(); ++i) {
            if(i == 0){
                result[i] = 0;
            }
            else if(i == 1) {
                result[i] = 1;
            }
            else if(i == 2) {
                result[i] = 2;
            }
            else {
                result[i] = result[i-1] + result[i-2];
            }
        }
        return result[n];
        
    }
};
