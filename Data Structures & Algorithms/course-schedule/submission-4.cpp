class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& myMap, vector<int>& status) {
        status[node] = 1;
        for(int i = 0; i < myMap[node].size(); ++i) {
            int w = myMap[node][i];
            if(status[w] == 1) {
                return false;
            }
            else if(status[w] == 0) {
                bool check = dfs(w, myMap, status);
                if(check == false) {
                    return false;
                }
            }
        }

        status[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses, 0);

        unordered_map<int, vector<int>> myMap;
        for(int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            myMap[b].push_back(a);
        }

        for(int i = 0; i < numCourses; ++i) {
            if(status[i] == 0) {
                bool result = dfs(i, myMap, status);
                if(result == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
