class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int max = *max_element(piles.begin(), piles.end());

        int left = 1; 
        int right = max;
        int res = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right -left) / 2;
            double cost = 0.0;
            for(int p: piles)
            {
                double hour = ceil(static_cast<double>(p) / mid);
                cost += hour;
            }

            if(cost <= static_cast<double>(h))
            {
                res = min(res, mid);
                right = mid - 1;
            }
            else
            {
                //cost > h
                left = mid+1;

            }
        }

        return res;
        
    }
};
