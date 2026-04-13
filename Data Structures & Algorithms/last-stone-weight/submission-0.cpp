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
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x < y || y < x)
            {
                int dif = abs(x-y);
                maxHeap.push(dif);
            }
            else
            {
                //both are equal we do nothing
                continue;
            }
        }

        return (maxHeap.size() == 1) ? maxHeap.top() : 0;
        
    }
};
