class Solution {
public:

    int dfs(int node, vector<vector<int>>& prereq, unordered_map<int,vector<int>>& myMap, vector<int>& courses)
    {
        //check if the node is being processed
        if(courses[node] == 1)
        {
            return 1; // cycle
        }

        if(courses[node] == 2)
        {
            return 2;
        }

        //otherwise course[node] = 0 so it is not visited
        courses[node] = 1; //now we will visit
        if(myMap[node].size() == 0)
        {
            //that class has no prereq
            courses[node] = 2;
            return 2;
        }
        for(int i = 0; i < myMap[node].size(); ++i)
        {
            int check = dfs(myMap[node][i], prereq, myMap, courses);
            if(check != 2)
            {
                return 1;
            }
        }
        courses[node] = 2;//done
        return 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())
        {
            return true;
        }


        //0 not visited 
        //1 currently being visited
        //2 done 
        vector<int> courses(numCourses, 0);

        unordered_map<int, vector<int>> myMap;
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            int c = prerequisites[i][0];
            int p = prerequisites[i][1];
            myMap[c].push_back(p);
        }

        for(int i = 0; i < numCourses; ++i)
        {
            int num = dfs(i, prerequisites, myMap, courses);
            if(num != 2)
            {
                return false;
            }

        }

        return true;

        
    }
};
