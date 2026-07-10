class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> boxs;

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }

                if(rows[i].find(c) != rows[i].end())
                {
                    return false;
                }
                rows[i].insert(c);

                if(cols[j].find(c) != cols[j].end())
                {
                    return false;
                }
                cols[j].insert(c);

                int idx = 3 * (i / 3) + (j / 3);
                if(boxs[idx].find(c) != boxs[idx].end())
                {
                    return false;
                }
                boxs[idx].insert(c);
            }
        }

        return true;
        
    }
};
