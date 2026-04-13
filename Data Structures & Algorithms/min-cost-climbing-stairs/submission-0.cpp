class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> result(cost.size() + 2, 0);

        int size = cost.size();
        for(int i = size-1; i >= 0; --i)
        {
            if(i >= cost.size())
            {
                result[i] = 0;
            }
            if(i != 0)
            {
                int first = cost[i] + result[i+1];
                int second = cost[i] + result[i+2];
                result[i] = min(first, second);
            }
            if(i == 0)
            {
                int first = cost[i] + result[i+1];
                int second = cost[i] + result[i+2];
                int third = result[i+1];
                result[i] = min({first, second, third});
                
            }

        }

        return result[0];
        
    }
};
