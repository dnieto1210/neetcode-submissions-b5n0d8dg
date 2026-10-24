class DisjointSets {
public:
    void addelements(int num)
    {
        for(int i = 0; i < num; ++i)
        {
            family.push_back(-1);
        }
        return;
    }

    int find(int elem)
    {
        if(family[elem] < 0)
        {
            return elem;
        }

        int root = find(family[elem]);
        family[elem] = root;
        return root;
    }

    void setUnion(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB)
        {
            return;
        }

        int total = family[rootA] + family[rootB];

        if(family[rootA] > family[rootB])
        {
            family[rootA] = rootB;
            family[rootB] = total;
        }
        else
        {
            family[rootB] = rootA;
            family[rootA] = total;
        }

        return;
    }

    int getSize(int elem)
    {
        int root = find(elem);
        return -1 * family[root];
    }

    int getValue(int elem)
    {
        return family[elem];
    }




private:
    vector<int> family;
};




class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        ///make edges and vertices
        unordered_map<int, pair<int,int>> myMap;
        DisjointSets mySets;
        using Node = pair<int, pair<int,int>>;
        vector<Node> edges;
        for(int i = 0; i < points.size(); ++i)
        {
            myMap[i] = {points[i][0], points[i][1]};
        }

        for(int i = 0; i < points.size(); ++i)
        {
            for(int j = i+1; j < points.size(); ++j)
            {
                int euc = (abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                edges.push_back({euc, {i, j}});
            }
        }

        mySets.addelements(points.size());

        priority_queue<Node, vector<Node>, greater<Node>> minHeap;
        for(int i = 0; i < edges.size(); ++i)
        {
            minHeap.push(edges[i]);
        }
        int edgeCount = 0;
        int result = 0;

        while(edgeCount != points.size()-1)
        {
            auto minEdge = minHeap.top();
            int v = minEdge.second.first;
            int u = minEdge.second.second;
            minHeap.pop();

            if(mySets.find(v) != mySets.find(u)){
                mySets.setUnion(mySets.find(v), mySets.find(u));
                result += minEdge.first;
                //edgeList.insert(minEdge);
                ++edgeCount;
            }
        }

        return result;
        
    }
};
