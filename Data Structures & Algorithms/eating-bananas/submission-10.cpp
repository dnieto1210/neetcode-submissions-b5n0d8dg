class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int minK = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int currHours = 0;
            for(int i = 0; i < piles.size(); ++i)
            {
                currHours += (piles[i] / mid);
                if(piles[i] % mid != 0)
                {
                    currHours += 1;
                }
            }

            if(currHours > h)
            {
                //we did not finish in time we should eat more bananas
                left = mid+1;
            }
            else
            {
                //currHours <= h
                //we were able to meet the time requirement lets see if we can eat less bananas
                minK = min(minK, mid);
                right = mid-1;
            }
        }

        return minK;
    }
};
