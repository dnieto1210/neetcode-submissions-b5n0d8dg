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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        vector<vector<int>> myIntervals;
        for(int i = 0; i < intervals.size(); ++i) {
            myIntervals.push_back({intervals[i].start, intervals[i].end});
        }

        sort(myIntervals.begin(), myIntervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int currEnd = myIntervals[0][1];
        minHeap.push(currEnd);
        for(int i = 1; i < myIntervals.size(); ++i) {
            int potStart = myIntervals[i][0];
            int potEnd = myIntervals[i][1];
            if(potStart >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(potEnd);
        }

        return minHeap.size();
        
    }
};
