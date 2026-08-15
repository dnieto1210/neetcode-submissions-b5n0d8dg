struct Node{
    unordered_map<char, Node*> children;
    bool isComplete = false;
    string w = "";
};


class Solution {
public:
    void addWord(string word)
    {
        Node* t = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(t->children.find(c) == t->children.end())
            {
                Node* temp = new Node();
                t->children[c] = temp;
            }

            t = t->children[c];
        }

        t->isComplete = true;
        t->w = word;
    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int row, int col, Node* node)
    {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] == 1)
        {
            return;
        }

        //mark visited
        visited[row][col] = 1;
        char c = board[row][col];

        if(node->children.find(c) == node->children.end())
        {
            visited[row][col] = 0;
            return;
        }
        node = node->children[c];

        if(node->isComplete)
        {
            node->isComplete = false;
            res.push_back(node->w);
        }

        dfs(board, visited, row, col-1, node);
        dfs(board, visited, row, col+1, node);
        dfs(board, visited, row-1, col, node);
        dfs(board, visited, row+1, col, node);
        visited[row][col] = 0;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        root= new Node();//create root

        //add all the words in our trie DS
        for(int i = 0; i < words.size(); ++i)
        {
            string curr = words[i];
            addWord(curr);
        }

        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                vector<vector<int>> visited(r, vector<int>(c, 0));
                dfs(board, visited, i, j, root);
            }
        }

        return res;
         


        
    }
private:
    Node* root;
    vector<string> res;
};
