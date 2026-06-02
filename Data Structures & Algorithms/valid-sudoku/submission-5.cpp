class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> box;

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }

                if(row[i].find(c) != row[i].end())
                {
                    return false;
                }
                else
                {
                    row[i].insert(c);
                }

                if(col[j].find(c) != col[j].end())
                {
                    return false;
                    col[j].insert(c);
                }
                else
                {
                    col[j].insert(c);
                }

                //box math
                int idx = 3 * (i / 3) + (j/3);
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
