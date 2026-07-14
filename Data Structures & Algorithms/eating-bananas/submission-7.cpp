class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int min = 1;
        int max = *(max_element(piles.begin(), piles.end()));
        int res = 1;

        while(min <= max)
        {
            int mid = min + (max-min) / 2;
            int count = 0;
            for(int i = 0; i < piles.size(); ++i)
            {
                int p = piles[i];
                count += ceil(static_cast<double>(p) / mid);
            }

            if(count > h)
            {
                min = mid + 1;
            }
            else
            {
                res = mid;
                max = mid -1;
            }
        }

        return res;
        
    }
};
