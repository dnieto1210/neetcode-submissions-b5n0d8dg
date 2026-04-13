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
                if(board[i][j] == '.')
                {
                    continue;
                }
                char num = board[i][j];
                if(rows[i].find(num) != rows[i].end())
                {
                    return false;
                }
                if(cols[j].find(num) != cols[j].end())
                {
                    return false;
                }

                int box_idx = ((i / 3) * 3) + (j / 3);
                if(boxs[box_idx].find(num) != boxs[box_idx].end())
                {
                    return false;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                boxs[box_idx].insert(num);


            }
        }

        return true;
        
    }
};
