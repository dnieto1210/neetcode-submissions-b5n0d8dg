class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        while(true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast)
            {
                break;
            }
        }

        //slow and fast are intersecting
        //set slow back to 0
        slow = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
            {
                break;
            }
        }

        return slow;
        
    }
};
