class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;
        for(int i : stones)
        {
            maxHeap.push(i);
        }

        while(maxHeap.size() > 1)
        {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();

            if(a < b)
            {
                maxHeap.push(b-a);
            }
            else if(b < a)
            {
                maxHeap.push(a-b);
            }

            //otherwise a == b and we dont do anything
        }

        return (maxHeap.empty()) ? 0 : maxHeap.top();
        
    }
};
