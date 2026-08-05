class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& adjList, vector<int>& dist, vector<int>& pred, int node)
    {
        queue<int> myNodes;
        dist[node] = 0;
        pred[node] = -2; // -2 means it was the starting vertex so node predecessor for this node 
        myNodes.push(node);

        while(!myNodes.empty())
        {
            int node = myNodes.front();
            myNodes.pop();
            if(adjList.find(node) != adjList.end())
            {
                vector<int>& neigh = adjList[node];
                for(int i = 0; i < neigh.size(); ++i)
                {
                    int endpoint = neigh[i];
                    if(dist[endpoint] == -1)
                    {
                        dist[endpoint] = 1 + dist[node];
                        pred[endpoint] = node;
                        myNodes.push(endpoint);
                    }
                    else
                    {
                        //we have already visited
                        //check if it is the pred if not then cycle
                        if(pred[node] != endpoint)
                        {
                            //cyclce
                            cycle = true;
                        }
                    }
                }


            }
            
        }

        return;
    }

    void BFS(unordered_map<int, vector<int>>& adjList, vector<int>& dist, vector<int>& pred)
    {
        count = 0;
        for(int i = 0; i < dist.size(); ++i)
        {
            int node = i;
            if(dist[node] == -1)
            {
                bfs(adjList, dist, pred, node);
                ++count;
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> pred(n, -1); //list of the nodes predessecros they are all null for now
        vector<int> dist(n, -1); //list of the nodes distances from start vertex
        

        unordered_map<int, vector<int>> adjList;
        for(const vector<int> edge: edges)
        {
            /// v----w
            int v = edge[0];
            int w = edge[1];
            adjList[v].push_back(w);
            adjList[w].push_back(v);
        }

        cycle = false;
        count = 0;

        BFS(adjList, dist, pred);

        if(count > 1 || cycle)
        {
            return false;
        }

        return true;

    }
private:
    int count;
    bool cycle;
};
