class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> prefix(size);
        std::vector<int> suffix(size);
        prefix[0] = 1;
        suffix[size-1] = 1;

        //prefix
        for(int i = 1; i < size; ++i)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        //suffix
        for(int i = size - 2; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i+1];
        }

        //result
        for(int i = 0; i < size; i++)
        {
            prefix[i] = prefix[i] * suffix[i];
        }

        return prefix;

        

    }
};
