class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<pair<int,int>> myNodes;
        int n = points.size();
        unordered_map<int, unordered_map<int,int>> distances;
        for(int i = 0; i < points.size(); ++i)
        {
            myNodes.push_back({points[i][0], points[i][1]});
        }
        for(int i = 0; i < points.size(); ++i)
        {
            for(int j = i+1; j < points.size(); ++j)
            {
                int a = myNodes[i].first;
                int b = myNodes[i].second;
                int c = myNodes[j].first;
                int d = myNodes[j].second;
                int euc = abs(a-c) + abs(b-d);
                distances[i][j] = euc;
                distances[j][i] = euc;

            }
        }
        vector<bool> visited(n, false);
        //vector<int> parent(n, -1);
        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        minHeap.push({0, 0});
        int minCost = 0;

        while(!minHeap.empty())
        {
            auto kv = minHeap.top();
            minHeap.pop();
            if(visited[kv.second])
            {
                continue;
            }

            visited[kv.second] = true;
            minCost += kv.first;

            for(int i = 0; i < points.size(); ++i)
            {
                if(!visited[i])
                {
                    int cost = distances[kv.second][i];
                    minHeap.push({cost, i});
                }
            }
        }

        return minCost;
    }
};
