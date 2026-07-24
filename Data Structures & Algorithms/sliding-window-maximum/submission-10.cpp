class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {


        int left = 0;
        priority_queue<pair<int,int>> maxHeap;
        vector<int> res;

        for(int right = 0; right < k; ++right)
        {
            maxHeap.push({nums[right], right});
        }

        res.push_back(maxHeap.top().first);

        for(int right = k; right < nums.size(); ++right)
        {
            int n = nums[right];
            int check_idx = maxHeap.top().second;

            while(check_idx <= (right-k))
            {
                maxHeap.pop();
                if(maxHeap.empty())
                {
                    break;
                }
                check_idx = maxHeap.top().second;
            }

            int check_num = INT_MIN;

            if(!maxHeap.empty())
            {
                check_num = maxHeap.top().first;
            }
    

            if(n > check_num)
            {
                res.push_back(n);
            }
            else
            {
                res.push_back(check_num);
            }

            maxHeap.push({n, right});
        }

        return res; 
    }
};
