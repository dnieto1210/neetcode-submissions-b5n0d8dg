class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {


        using Node = std::pair<int, int>;
        std::priority_queue<Node> maxHeap;

        std::vector<int> result; 
        for(int i = 0; i < k; ++i)
        {
            maxHeap.push({nums[i], i});
        }

        result.push_back(maxHeap.top().first);

        int left = 1;
        int right = k;

        while(right < nums.size())
        {
            int val = nums[right];
            maxHeap.push({val, right});
            if(maxHeap.top().second >= left && maxHeap.top().second <= right)
            {
                result.push_back(maxHeap.top().first);
            }
            else
            {
                //it is not in our window
                while(maxHeap.top().second < left)
                {
                    //elimate the elements not in our windown
                    maxHeap.pop();
                }
                result.push_back(maxHeap.top().first);
            }

            ++left;
            ++right;
        }

        return result;
        
    }
};
