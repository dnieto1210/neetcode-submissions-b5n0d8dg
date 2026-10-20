/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        //if the meetings overlap they you can not attend all meetings
        vector<vector<int>> times;
        for(int i = 0; i < intervals.size(); ++i)
        {
            int start = intervals[i].start;
            int end = intervals[i].end;
            times.push_back({start, end});
        }
        sort(times.begin(), times.end());

        int currX = times[0][0];
        int currY = times[0][1];

        for(int i = 1; i < times.size(); ++i)
        {
            int potX = times[i][0];
            int potY = times[i][1];

            if(potX < currY && potX >= currX)
            {
                //they overlap
                return false;
            }
            else if(currX < potX && currY <= potX)
            {
                currX = potX;
                currY = potY;
            }

        }

        return true;
        
    }
};
