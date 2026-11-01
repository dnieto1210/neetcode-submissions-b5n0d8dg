class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board) {

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return;
        }
        if(visited[row][col]) {
            return;
        }
        if(board[row][col] == 'X') {
            return;
        }

        visited[row][col] =true;
        dfs(row-1, col, visited, board);
        dfs(row+1, col, visited, board);
        dfs(row, col-1, visited, board);
        dfs(row, col+1, visited, board);
        return;

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board[0].size(); ++i) {
            dfs(0, i, visited, board);
            dfs(board.size()-1, i, visited, board);
        }
        for(int i = 0; i < board.size(); ++i) {
            dfs(i, 0, visited, board);
            dfs(i, board[0].size()-1, visited, board);
        }

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                char c = board[i][j];
                if(visited[i][j] == false && c == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        return;
        
    }
};
