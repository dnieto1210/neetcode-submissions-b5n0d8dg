class Solution {
public:
    void backtracking(int r)
    {
        if(r == total)
        {
            result.push_back(temp);
            return;
        }


            string curr = temp[r];
            for(int j = 0; j < total; ++j)
            {
                if(col[j] == true)
                {
                    continue; // this column is already taken
                }

                //check the diagonals
                int pot_row = r - 1;
                int pot_col = j - 1;
                bool legal = true;
                while(pot_row >= 0 && pot_col >= 0)
                {
                    if(temp[pot_row][pot_col] == 'Q')
                    {
                        legal = false; //same diagonal
                        break;

                    }
                    --pot_row;
                    --pot_col;
                }

                pot_row = r - 1;
                pot_col = j + 1;
                while(legal && pot_row >= 0 && pot_col < total)
                {
                    if(temp[pot_row][pot_col] == 'Q')
                    {
                        legal = false;
                        break;
                    }
                    --pot_row;
                    ++pot_col;
                }

                if(legal)
                {
                    row[r] = true;
                    col[j] = true;
                    temp[r][j] = 'Q';
                    backtracking(r+1);
                    col[j] = false;
                    temp[r][j] = '.';
                }
            }

            return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string curr = "";
        total = n;
        row.resize(total, false);
        col.resize(total, false);

        for(int i = 0; i < n; ++i)
        {
            curr += '.';
        }
        for(int i = 0; i < n; ++i)
        {
            temp.push_back(curr);
        }

        int i = 0;
        backtracking(0);
        return result;

    }
private:
    vector<vector<string>> result;
    vector<string> temp;
    vector<bool> row;
    vector<bool> col;
    int total;

};
