class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using Node = pair<int,int>;
        priority_queue<pair<double, Node>, vector<pair<double,Node>>> maxHeap;
        for(int i =0; i < points.size(); ++i)
        {
            vector<int> coords = points[i];
            int first = coords[0];
            int second = coords[1];

            int first_square = first * first;
            int second_square = second * second;
            int sum = first_square + second_square;
            double euclid = sqrt(sum);
            pair<int, int> c = {first, second};
            maxHeap.push({euclid, c});
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }

        }

        vector<vector<int>> result;
        while(!maxHeap.empty())
        {
            vector<int> temp;
            pair p = maxHeap.top().second;
            temp.push_back(p.first);
            temp.push_back(p.second);
            result.push_back(temp);
            maxHeap.pop();
        }

        return result;
        
    }
};
