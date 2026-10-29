class Trie {
public:
    struct Node{
        unordered_map<char, Node*> children;
        bool isFinished = false;
        string word = "";
    };

    Trie() {
        root = new Node();
    }

    bool findWord(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) == traverse->children.end())
            {
                return false;
            }
            traverse = traverse->children[c];
        }

        return traverse->isFinished;
    }

    void insertWord(string word) {
        Node* traverse = root;
        for(int i = 0;  i < word.size(); ++i) 
        {
            char c = word[i];
            if(traverse->children.find(c) == traverse->children.end()) {
                traverse->children[c] = new Node();
            }
            traverse = traverse->children[c];
        }
        traverse->isFinished = true;
        traverse->word = word;
        return;
    }

    Node* explore() {
        return root;
    }


private:
    Node* root;
};

class Solution {
public:
    void dfs(int row, int col, Trie::Node* explore, vector<vector<bool>>& visited, vector<vector<char>>& board) {

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        {
            return;
        }

        if(visited[row][col])
        {
            return;
        }

        char c = board[row][col];
        if(explore->children.find(c) == explore->children.end()) {
            return;
        }
        if(explore->children[c]->isFinished) {
            result.push_back(explore->children[c]->word);
            explore->children[c]->isFinished = false;
        }

        visited[row][col] = true;
        dfs(row-1, col, explore->children[c], visited, board);
        dfs(row+1, col, explore->children[c], visited, board);
        dfs(row, col-1, explore->children[c], visited, board);
        dfs(row, col+1, explore->children[c], visited, board);
        visited[row][col] = false;

        return;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < words.size(); ++i) {
            string curr = words[i];
            tree.insertWord(curr);
        }

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                Trie::Node* explore = tree.explore();
                dfs(i, j, explore, visited, board);
            }
        }

        return result;


    }
private:
    Trie tree;
    vector<string> result;
        
};
