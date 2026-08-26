class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> box;


        int R = board.size();
        int C = board[0].size();
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }
                //otherwise it is a valid digit

                //check row first
                if(row[i].find(c) != row[i].end())
                {
                    return false;
                }
                else
                {
                    row[i].insert(c);
                }

                //check col
                if(col[j].find(c) != col[j].end())
                {
                    return false;
                }
                else
                {
                    col[j].insert(c);
                }

                //check box
                int idx = (3 * (i/3)) + (j / 3);
                if(box[idx].find(c) != box[idx].end())
                {
                    return false;
                }
                else
                {
                    box[idx].insert(c);
                }
            }
        }

        return true;
        
    }
};
