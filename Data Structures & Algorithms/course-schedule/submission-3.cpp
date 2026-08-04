class Solution {
public:
    bool isAcyclicDFS(unordered_map<int, vector<int>>& adjList, vector<int>& status, int node)
    {
        status[node] = 1; //active
        vector<int>& neigh = adjList[node];

        for(int i = 0; i < neigh.size(); ++i)
        {
            int pot = neigh[i];
            if(status[pot] == 1)
            {
                return false;
            }
            else if(status[pot] == 0)
            {
                bool c = isAcyclicDFS(adjList, status, pot);
                if(c == false)
                {
                    return false;
                }
            }
        }

        status[node] = 2; //finished
        return true;
        
    }
    bool IsAcyclic(unordered_map<int, vector<int>>& adjList, vector<int>& status)
    {
        for(auto kv: adjList)
        {
            int node = kv.first;
            vector<int>& neigh = kv.second;
            if(status[node] == 0)
            {
                bool check = isAcyclicDFS(adjList, status, node);
                if(check == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            ///v --> w
            int v = prerequisites[i][1];
            int w = prerequisites[i][0];
            adjList[v].push_back(w);
        }

        //0 is new, 1 is active, and 2 is finished
        vector<int> status(numCourses, 0);

        bool res = IsAcyclic(adjList, status);

        return res;
        
    }
};
