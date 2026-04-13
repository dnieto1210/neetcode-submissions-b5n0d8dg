class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {


        int largest = *max_element(piles.begin(), piles.end());

        int left = 1;
        int right = largest;
        int result = largest;

        while(left <= right)
        {
            int mid = left + (right-left) / 2;
            int times = 0;
            for(int i = 0; i < piles.size(); ++i)
            {
                times += (piles[i] + mid - 1) / mid;
            }
            if(times > h)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                result = mid;
            }


        }

        return result;
        
    }
};
