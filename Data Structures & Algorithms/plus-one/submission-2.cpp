class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int rem = 1;
        for(int i = digits.size()-1; i >= 0; --i) {
            int res = digits[i] + rem;
            if(res == 10) {
                digits[i] = 0;

            }
            else {
                digits[i] = res;
                return digits;
            }
        }

        vector<int> result(digits.size()+1, 0);
        result[0] = 1;
        return result;


        
    }
};
