
class DisjointSets{
public:
    void addNodes(int num)
    {
        for(int i = 0; i < num; ++i)
        {
            families.push_back(-1);
        }
    }

    int find(int node)
    {
        if(families[node] < 0)
        {
            return node;
        }
        else
        {
            int root = find(families[node]);
            families[node] = root;
            return root;
        }
    }

    //this function will implement union by size
    //if the two sets are the same size, we make the tree containing the second argument point to the tree containng the first
    bool setUnion(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);

        if(root_a == root_b)
        {
            //they are already unioned
            return false;
        }

        int size_a = -1 * families[root_a];
        int size_b = -1 * families[root_b];
        int total_size = size_a + size_b;

        if(size_b <= size_a)
        {
            families[root_b] = root_a;
            families[root_a] = -1 * total_size;
        
        }
        else
        {
            families[root_a] = root_b;
            families[root_b] = -1 * total_size;
        }

        return true; //properly unioned

    }



private:
    vector<int> families;
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DisjointSets graph;
        int n = edges.size();
        graph.addNodes(n+1);

        for(const vector<int>& edge : edges)
        {
            /// v----w
            int v = edge[0];
            int w = edge[1];

            if(!graph.setUnion(v,w))
            {
                return {v, w};
            }
        }

        return {};
        
    }
};
