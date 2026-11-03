class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        unordered_map<int, vector<vector<int>>> myMap;

        for(int i = 0; i < times.size(); ++i) {
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];

            myMap[u].push_back({v, weight});
        }
        dist[k] = 0;
        using Node = pair<int,int>;
        //{distance, node}
        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        minHeap.push({0, k});

        while(!minHeap.empty()) {
            int node = minHeap.top().second;
            int weight = minHeap.top().first;
            minHeap.pop();

            if(dist[node] < weight) {
                //this is stale
                continue;
            }

            for(int i = 0; i < myMap[node].size(); ++i) {
                int v = myMap[node][i][0];
                int edge = myMap[node][i][1];

                if(dist[v] > edge+ dist[node]) {
                    dist[v] = edge + dist[node];
                    minHeap.push({dist[v], v});
                }
            }
        }

        int maxE = INT_MIN;

        for(int i = 1; i < dist.size(); ++i) {
            if(dist[i] == INT_MAX) {
                return -1;
            }

            maxE = max(maxE, dist[i]);

        }

        return maxE;
        
    }
};
