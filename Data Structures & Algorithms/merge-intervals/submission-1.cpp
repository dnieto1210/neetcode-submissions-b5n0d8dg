class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        for(int i = 0; i < intervals.size(); ++i)
        {
            int potStart = intervals[i][0];
            int potEnd = intervals[i][1];

            if(potStart <= currEnd)
            {
                currStart = min(currStart, potStart);
                currEnd = max(currEnd, potEnd);
            }
            else
            {
                //potStart > currEnd
                result.push_back({currStart, currEnd});
                currStart = potStart;
                currEnd = potEnd;
            }
        }

        result.push_back({currStart, currEnd});

        return result;
        
    }
};
