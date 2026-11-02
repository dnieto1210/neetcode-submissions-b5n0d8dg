class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& myMap, vector<bool>& visited) {
        if(visited[node] == true) {
            return;
        }
        visited[node] = true;
        for(int i =0; i < myMap[node].size(); ++i) {
            int w =myMap[node][i];
            dfs(w, myMap, visited);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> myMap;
        for(int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            myMap[a].push_back(b);
            myMap[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(visited[i] == false) {
                dfs(i, myMap, visited);
                ++count;
            }
        }

        return count;

    }
};
