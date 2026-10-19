class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        myK = k;
        for(int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if(minHeap.size() < k)
            {
                minHeap.push(n);
            }
            else
            {
                // == k
                if(n > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(n);
                }

            }
        }
        
    }
    
    int add(int val) {

        if(minHeap.size() < myK)
        {
            minHeap.push(val);
        }
        else
        {
            if(val > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(val);
            }
        }

        return minHeap.top(); 
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int myK;
};
