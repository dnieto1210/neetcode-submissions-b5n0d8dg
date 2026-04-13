class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


        priority_queue<int, vector<int>> maxHeap;
        for(int nums : stones)
        {
            maxHeap.push(nums);
        }

        while(maxHeap.size() != 0 && maxHeap.size() != 1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if(x == y)
            {
                continue;
            }
            else
            {
                int res = abs(x-y);
                maxHeap.push(res);
            }
        }


        return (maxHeap.empty()) ? 0 : maxHeap.top();
        
    }
};
