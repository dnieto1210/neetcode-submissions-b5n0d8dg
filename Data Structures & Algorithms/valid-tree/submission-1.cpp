class Solution {
public:
    bool dfs(int node, vector<int>& dist, vector<int>& pred, unordered_map<int, vector<int>>& adjList) {

        for(int i = 0; i < adjList[node].size(); ++i) {
            int w = adjList[node][i];
            if(dist[w] == -1) {
                pred[w] = node;
                dist[w] = dist[node] + 1;
                dfs(w, dist, pred, adjList);
            }
            else {
                //cycle
                if(w == pred[node]){
                    continue;
                }
                else {
                    return false;
                }
            }
        }

        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> dist(n, -1);
        vector<int> pred(n, -1);
        unordered_map<int, vector<int>> adjList;


        for(int i = 0; i < edges.size(); ++i) {
            int v = edges[i][0];
            int w = edges[i][1];
            adjList[v].push_back(w);
            adjList[w].push_back(v);
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(dist[i] == -1) {
                dist[i] = 0;
                bool check = dfs(i, dist, pred, adjList);
                if(check == false) {
                    return false;
                }
                ++count;
            }
        }

        if(count > 1) {
            return false;
        }

        return true;



    }
};
