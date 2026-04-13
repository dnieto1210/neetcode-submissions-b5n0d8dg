class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        using Node = std::pair<int,int>;
        std::priority_queue<Node, std::vector<Node>> maxHeap;
        std::vector<int> result;

        for(int i =0; i < k; ++i)
        {
            maxHeap.push({nums[i], i});
        }
        result.push_back(maxHeap.top().first);

        for(int i = k; i < nums.size(); ++i)
        {
            maxHeap.push({nums[i], i});
            auto t = maxHeap.top();
            if(t.second >= (i-k+1))
            {
                result.push_back(t.first);
            }
            else
            {
                while(maxHeap.top().second < (i-k+1))
                {
                    maxHeap.pop();
                }
                result.push_back(maxHeap.top().first);
            }

        }
        return result;
    }
};
