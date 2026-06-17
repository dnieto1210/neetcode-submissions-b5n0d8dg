class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        using Node = pair<int,int>; //value, idx
        priority_queue<Node, vector<Node>> maxHeap;

        for(int i = 0; i < k; ++i)
        {
            int num = nums[i];
            maxHeap.push({num, i});
        }
        result.push_back(maxHeap.top().first);
        for(int i = k; i < nums.size(); ++i)
        {
            int num = nums[i];
            maxHeap.push({num,i});
            while(!maxHeap.empty() && maxHeap.top().second <= i-k)
            {
                maxHeap.pop();
            }
            result.push_back(maxHeap.top().first);
        }

        return result;
        
    }
};
