class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int max = 0;
        int total = 0;
        for(int i = 0; i < piles.size(); ++i)
        {
            int num = piles[i];
            if(num > max)
            {
                max = num;
            }
            total += num;
        }
        
        //we will do bs on 1-max elements
        int left = 1;
        int right = max;
        int minEating = max;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            long int time = 0;
            for(int p : piles)
            {
                time += ceil(static_cast<double>(p) / mid);
            }
            if(time <= h)
            {
                minEating = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return minEating;
    }
};
