class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>> maxHeap;

        for(int i = 0; i < k && i < nums.size(); ++i)
        {
            maxHeap.push({nums[i], i});
        }


        int start = 0;
        int end = k-1;

        while(end < nums.size())
        {
            while(maxHeap.top().second < start || maxHeap.top().second > end)
            {
                maxHeap.pop();
            }
            int max = maxHeap.top().first;

            result.push_back(max);
            start++;
            end++;
            if(end < nums.size())
            {
                maxHeap.push({nums[end], end});
            }
        }

        return result;
        
    }
};
