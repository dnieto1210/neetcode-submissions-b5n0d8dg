class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int,unordered_set<int>> rows;
        unordered_map<int,unordered_set<int>> cols;
        unordered_map<int,unordered_set<int>> boxes;

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }
                //otherwise we have a valid char
                if(rows[i].find(c) != rows[i].end())
                {
                    return false;
                }
                else
                {
                    rows[i].insert(c);
                }

                if(cols[j].find(c) != cols[j].end())
                {
                    return false;
                }
                else
                {
                    cols[j].insert(c);
                }

                //check box
                // col /3 + (row / 3) * 3
                int b = (j / 3) + ((i/3) * 3);
                if(boxes[b].find(c) != boxes[b].end())
                {
                    return false;
                }
                else
                {
                    boxes[b].insert(c);
                }

            }
        }

        return true;
        
    }
};
