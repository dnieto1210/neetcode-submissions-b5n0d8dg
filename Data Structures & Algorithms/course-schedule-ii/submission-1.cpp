class Solution {
public:
    bool acyclic(int node, unordered_map<int, vector<int>>& neighbors, vector<int>& status) {
        status[node] = 1;
        for(int i = 0; i < neighbors[node].size(); ++i) {
            int w = neighbors[node][i];
            if(status[w] == 1) {
                return false;
            }
            else if(status[w] == 0) {
                bool check = acyclic(w, neighbors, status);
                if(check == false) {
                    return false;
                }
            }
        }
        status[node]= 2;
        return true;
    }

    int topo(int node, int clock, unordered_map<int, vector<int>>& neighbors, vector<int>& status, vector<int>& result) {
        status[node] = 1;
        for(int i =0; i < neighbors[node].size(); ++i) {
            int w = neighbors[node][i];
            if(status[w] == 0) {
                clock = topo(w, clock, neighbors, status, result);
            }
        }

        status[node] = 2;
        result[clock] = node;
        clock = clock-1;
        return clock;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        //check if there is a cycle 
        vector<int> status(numCourses, 0);
        unordered_map<int, vector<int>> neighbors;

        for(int i = 0; i < prerequisites.size(); ++i) {
            int w = prerequisites[i][0];
            int v = prerequisites[i][1];
            neighbors[v].push_back(w);
        }

        for(int i = 0; i < numCourses;++i) {
            if(status[i] == 0) {
                bool res = acyclic(i, neighbors, status);
                if(res == false) {
                    return {};
                }
            }
        }

        //if we get to this point we know we dont have a cycle

        vector<int> topStatus(numCourses, 0);
        int clock = numCourses-1;
        vector<int> result(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if(topStatus[i] == 0) {
                clock = topo(i, clock, neighbors, topStatus, result);

            }
        }
        return result;
    }
};
