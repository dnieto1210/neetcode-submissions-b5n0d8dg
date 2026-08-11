class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i)
        {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if(nextStart <= currEnd)
            {
                currStart = min(currStart, nextStart);
                currEnd = max(currEnd, nextEnd);
            }
            else
            {
                result.push_back({currStart, currEnd});
                currStart = nextStart;
                currEnd = nextEnd;
            }
        }
        result.push_back({currStart, currEnd});

        return result;
        
    }
};
