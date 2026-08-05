class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, int node)
    {
        if(visited[node] == false)
        {
            visited[node] = true;
            vector<int>& neighbors = adjList[node];
            for(int i = 0; i < neighbors.size(); ++i)
            {
                int w = neighbors[i];
                if(visited[w] == false)
                {
                    dfs(adjList, visited, w);
                }
                //otherwise it has already been visited
            }
        }
    }
    void DFSWrapper(unordered_map<int, vector<int>>& adjList, vector<bool>& visited)
    {
        //unmark all of vertices
        //they are already unmarked

        count = 0;

        //for each vertices v, check if unmarked and do dfs
        for(int i = 0; i < numVertices; ++i)
        {
            int v = i;
            if(visited[v] == false)
            {
                ++count;
                dfs(adjList, visited, v);
            }
        }

        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adjList;
        vector<bool> visited(n, false);
        numVertices = n;

        for(int i = 0; i < edges.size(); ++i)
        {
            vector<int>& temp = edges[i];
            adjList[temp[0]].push_back(temp[1]);
            adjList[temp[1]].push_back(temp[0]);
        }

        DFSWrapper(adjList, visited);
        return count;
    }
private:
    int count;
    int numVertices;
};
