class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;

        for(int i = 0; i < piles.size(); ++i)
        {
            if(piles[i] > max)
            {
                max = piles[i];
            }

        }
        
        int start = 1;
        int end = max;
        int result = max;

        while(start <= end)
        {
            int k = (start + end) /2;
            int totalHours = 0;

            for(int& p : piles)
            {
                double b = std::ceil(static_cast<double>(p) / k);
                totalHours += static_cast<int>(b);
            }

            if(totalHours <= h)
            {
                end = k -1;
                result = std::min(result, k);
            }
            else
            {
                start = k + 1;
            }

        }

        return result;




    }
};
