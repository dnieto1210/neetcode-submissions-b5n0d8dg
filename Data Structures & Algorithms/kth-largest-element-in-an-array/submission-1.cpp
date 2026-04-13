class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::priority_queue<int> maxHeap;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxHeap.push(nums[i]);
        }

        int largest = 0;

        while(k > 0)
        {
            largest = maxHeap.top();
            maxHeap.pop();
            --k;
        }
        return largest;
        
    }
};
