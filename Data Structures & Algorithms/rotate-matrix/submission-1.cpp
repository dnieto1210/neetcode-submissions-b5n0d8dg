class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        

        int rows = matrix.size();
        //transpose
        for(int i = 0; i < rows; ++i)
        {
            for(int j = i; j < rows; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse the rows 

        for(auto& v : matrix)
        {

            std::reverse(v.begin(), v.end());
        }

        return;

        
    }
};
