class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


        sort(intervals.begin(), intervals.end());
        int result = 0;
        int currX = intervals[0][0];
        int currY = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i)
        {
            int potX = intervals[i][0];
            int potY = intervals[i][1];

            if(potX < currY && potX >= currX)
            {
                //they overlap
                ++result;
                //we keep the timestamp that ends earilier
                if(potY < currY)
                {
                    currY = potY;
                    currX = potX;
                }
            }
            else if(potX >= currY && potX > currX)
            {
                //no overlap
                currX = potX;
                currY = potY;
            }
        }

        return result;
        
    }
};
