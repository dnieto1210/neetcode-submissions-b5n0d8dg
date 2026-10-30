class Solution {
public:
    void dfs(int n, unordered_set<int>& rows, unordered_set<int>& cols) {

        if(n == size)
        {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < size; ++i)
        {
            //you are gonna occupy a row each queen will be in a row
            //rows.insert(n);
            //check if col is occupied
            if(cols.find(i) != cols.end())
            {
                continue;
            }

            //otherwise this col is empty and check if diagonals
            //check upper right diagonal
            int checkRow = n-1;
            int checkCol = i+1;
            bool valid = true;
            while(checkRow >= 0 && checkCol < size) {
                char check = temp[checkRow][checkCol];
                if(check == 'Q') {
                    valid = false;
                    break;
                }
                else {
                    --checkRow;
                    ++checkCol;
                }
            }
            if(valid == false) {
                continue;
            }

            //check upper left diagonal
            checkRow = n-1;
            checkCol = i-1;
            while(checkRow >= 0 && checkCol >= 0) {
                char check = temp[checkRow][checkCol];
                if(check == 'Q') {
                    valid = false;
                    break;
                }
                else {
                    --checkRow;
                    --checkCol;
                }
            }
            if(valid == false) {
                continue;
            }

            //otherwise we have found a valid position
            rows.insert(n);
            cols.insert(i);

            //make the string
            string tempo = "";
            for(int j = 0; j < size; ++j)
            {
                if(j == i)
                {
                    tempo.push_back('Q');
                }
                else
                {
                    tempo.push_back('.');
                }

            }
            temp.push_back(tempo);
            dfs(n+1, rows, cols);
            temp.pop_back();
            rows.erase(n);
            cols.erase(i);
        }

        return;

    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        unordered_set<int> rows;
        unordered_set<int> cols;
        dfs(0, rows, cols);
        return result;
        
    }
private:
    vector<vector<string>> result;
    vector<string> temp;
    int size;
};
