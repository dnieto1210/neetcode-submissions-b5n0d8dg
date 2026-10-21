class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int currX = intervals[0][0];
        int currY = intervals[0][1];
        int remove = 0;

        for(int i = 1; i < intervals.size(); ++i)
        {
            int potX = intervals[i][0];
            int potY = intervals[i][1];
            if(potX < currY && potX >= currX)
            {
                //they overlap
                if(potY < currY)
                {
                    currX = potX;
                    currY = potY;
                }
                ++remove;
            }
            else
            {
                currX = potX;
                currY = potY;

            }
        }
        
        return remove;
    }
};
