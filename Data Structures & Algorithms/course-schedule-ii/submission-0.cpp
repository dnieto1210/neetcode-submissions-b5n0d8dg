class Solution {
public:
    int topoSortDFS(unordered_map<int, vector<int>>& adjList, vector<int>& status, int node, int clock)
    {
        status[node] = 1; //active;
        vector<int> empty; //emptly list;
        vector<int>& neigh = (adjList.find(node) != adjList.end()) ? adjList[node] : empty;
        for(int i = 0; i < neigh.size(); ++i)
        {
            int curr_node = neigh[i];
            if(status[curr_node] == 0)
            {
                
                clock = topoSortDFS(adjList, status, curr_node, clock);
                if(clock == -100)
                {
                    return -100;
                }
            }
            else if(status[curr_node] == 1)
            {
                //cycle
                return -100;
            }
        }

        status[node] = 2; //finished
        ordering[clock] = node;
        clock = clock - 1;
        return clock;
    }
    vector<int> topoSort(unordered_map<int, vector<int>>& adjList, vector<int>& status)
    {
        int clock = V;
        for(int i = 0; i < V+1; ++i)
        {
            int node = i;
            if(status[node] == 0) 
            {
                clock = topoSortDFS(adjList, status, node, clock);
                if(clock == -100)
                {
                    return {};
                }
            }
        }

        vector<int> result = ordering;
        return ordering;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        ordering.resize(numCourses, 0);
        vector<int> status(numCourses, 0);
        unordered_map<int, vector<int>> adjList;
        V = numCourses-1;

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            // v ---> w
            int v = prerequisites[i][1];
            int w = prerequisites[i][0];

            adjList[v].push_back(w);
        }

        vector<int> finalRes = topoSort(adjList, status);
        return finalRes;

        
    }
private:
    vector<int> ordering;
    int V;
};
