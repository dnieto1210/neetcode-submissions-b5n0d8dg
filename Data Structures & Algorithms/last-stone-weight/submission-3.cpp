class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int n : stones)
        {
            maxHeap.push(n);
        }

        while(maxHeap.size() > 1)
        {
            int one = maxHeap.top();
            maxHeap.pop();
            int two = maxHeap.top();
            maxHeap.pop();
            if(one < two)
            {
                maxHeap.push(two-one);
            }
            else if(one > two)
            {
                maxHeap.push(one - two);
            }
        }

        if(maxHeap.size() == 0)
        {
            return 0;
        }
        return maxHeap.top();
        
    }
};
