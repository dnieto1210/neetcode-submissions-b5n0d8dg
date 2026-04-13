class KthLargest {
public:

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i =0; i < nums.size(); ++i)
        {
            minHeap.push(nums[i]);
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
    }
    
    int add(int val) {
        if(minHeap.size() >= K && val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        else if(minHeap.size() < K)
        {
            minHeap.push(val);
        }

        return minHeap.top();
        
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
};
