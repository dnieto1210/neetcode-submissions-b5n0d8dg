class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> result(cost.size() + 2, 0);

        int size = cost.size()-1;
        for(int i = size; i >= 0; --i)
        {
            if(i >= cost.size())
            {
                result[i] = 0;
            }
            else
            {
                int first = cost[i] + result[i+1];
                int second = cost[i] + result[i+2];
                result[i] = min(first, second);
            }

        }

        return min(result[0], result[1]);
        
    }
};
