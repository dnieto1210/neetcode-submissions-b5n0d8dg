class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        auto it = max_element(piles.begin(), piles.end());
        int max = *it;

        int start = 1;
        int end = max;
        int k = max;

        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int total_hours = 0;

            for(int& p : piles)
            {
                double d = static_cast<double>(p) / mid;
                int hours = ceil(d);
                total_hours += hours;

            }

            if(total_hours > h)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
                k = mid;
            }

        }


        return k;
        
    }
};
