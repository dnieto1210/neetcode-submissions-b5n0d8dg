class DisjointSets{
public:

    void addElements(int ele) {
        for(int i = 0; i < ele; ++i) {
            family.push_back(-1);
        }
        return;
    }

    int find(int ele) {
        if(family[ele] < 0) {
            return ele;
        }

        int root = find(family[ele]);
        family[ele] = root;
        return root;
    }

    bool unionEle(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) {
            return false;
        }

        int sizeA = family[rootA];
        int sizeB = family[rootB];

        if(sizeA > sizeB) {
            family[rootA] = rootB;
            family[rootB] = sizeA + sizeB;
        }
        else {
            family[rootB] = rootA;
            family[rootA] = sizeA + sizeB;
        }

        return true;
    }



private:
    vector<int> family;
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DisjointSets fam;
        fam.addElements(edges.size()+1);
        int recent = -1;
        for(int i = 0; i < edges.size(); ++i) {
            if(fam.unionEle(edges[i][0], edges[i][1]) == false) {
                recent = i;
            }
        }
        return edges[recent];
        
    }
};
