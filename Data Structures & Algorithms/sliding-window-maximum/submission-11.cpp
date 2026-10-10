class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        using Node = pair<int,int>;
        priority_queue<Node> maxHeap;
        vector<int> result;
        for(int i = 0; i < k; ++i)
        {
            maxHeap.push({nums[i], i});
        }
        result.push_back(maxHeap.top().first);

        int left = 1;
        int right = k;
        while(right < nums.size())
        {
            maxHeap.push({nums[right], right});
            while(!maxHeap.empty() && maxHeap.top().second < left)
            {
                maxHeap.pop();
            }
            result.push_back(maxHeap.top().first);
            ++left;
            ++right;
        }

        return result;


        
    }
};
