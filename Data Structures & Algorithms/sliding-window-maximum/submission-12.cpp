class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> myD; // we will put the index
    vector<int> result;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        int n = nums[i];
        
        while((!myD.empty() && n > nums[myD.back()]) || (!myD.empty() && myD.back() <= (i-k)))
        {
            myD.pop_back();
        }
        
        while((!myD.empty() && n > nums[myD.front()]) || (!myD.empty() && myD.front() <= (i-k)))
        {
            myD.pop_front();
        }
        
        myD.push_front(i);
        if(i + 1 >= k)
        {
            result.push_back(nums[myD.back()]);
        }
    }
    
    return result;


        
    }
};
