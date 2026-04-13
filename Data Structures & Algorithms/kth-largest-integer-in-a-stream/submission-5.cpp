class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>> maxHeap;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxHeap.push(nums[i]);
        }
        
    }
    
    int add(int val) {

        vector<int> temp;

        maxHeap.push(val);
        int iter = kth;

        while(iter > 0)
        {

            temp.push_back(maxHeap.top());
            maxHeap.pop();
            --iter;
        }

        int result = temp[temp.size()-1];

        //put elements back in heap
        for(int i = 0; i < temp.size(); ++i)
        {
            maxHeap.push(temp[i]);
        }

        return result;
        
    }
};
