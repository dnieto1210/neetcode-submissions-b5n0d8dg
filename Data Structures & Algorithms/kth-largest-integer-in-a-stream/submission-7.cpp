class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;

        for(int i = 0; i < nums.size(); ++i)
        {
            
            if(i >= k)
            {
                if(minHeap.top() < nums[i])
                {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
                
            }
            else
            {
                minHeap.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {
        if(minHeap.size() >= K)
        {
            if(val > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(val);
            }

            return minHeap.top();

        }
        else
        {
            minHeap.push(val);
            return minHeap.top();
        }
        
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
};
