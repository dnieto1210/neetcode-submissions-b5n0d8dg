class Solution {
public:
    void dfs(int node, vector<int>& dist, vector<int>& pred, unordered_map<int, vector<int>>& adjList, unordered_map<int, unordered_map<int, int>>& edgeLabels) {

        for(int i = 0; i < adjList[node].size(); ++i) {
            int w = adjList[node][i];
            if(dist[w] == -1) {
                pred[w] = node;
                dist[w] = dist[node] + 1;
                edgeLabels[node][w] = 1; //discovery
                edgeLabels[w][node] = 1;
                dfs(w, dist, pred, adjList, edgeLabels);
            }
            else {
                //cycle
                if(w == pred[node]){
                    continue;
                }
                else {
                    edgeLabels[node][w] = 2; //back edge
                    edgeLabels[w][node] = 2;
                    
                }
            }
        }

        return;

    }
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> dist(n, -1);
        vector<int> pred(n, -1);

        //0 for unexplored, 1 for discovery, 2 for back edge 
        unordered_map<int, unordered_map<int,int>> edgeLabels;
        unordered_map<int, vector<int>> adjList;


        for(int i = 0; i < edges.size(); ++i) {
            int v = edges[i][0];
            int w = edges[i][1];
            adjList[v].push_back(w);
            adjList[w].push_back(v);
            edgeLabels[v][w] = 0; //label unexplored
            edgeLabels[w][v] = 0;
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(dist[i] == -1) {
                dist[i] = 0;
                dfs(i, dist, pred, adjList, edgeLabels);
                ++count;
            }
        }

        if(count > 1) {
            return false;
        }

        for(auto kv: edgeLabels) {
            for(auto edge: kv.second) {
                int label = edge.second;
                if(label == 2) {
                    return false;
                }
            }
        }

        return true;



    }
};
