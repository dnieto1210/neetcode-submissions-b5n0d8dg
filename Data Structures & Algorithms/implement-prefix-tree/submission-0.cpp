struct Node{
    std::unordered_map<char, Node*> children;
    bool isComplete;
};

class PrefixTree {
public:
    PrefixTree() {
        root = new Node();
        root->isComplete = false;
    }
    
    void insert(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                //letter is already in trie
                traverse = traverse->children[c];
                continue;
            }
            else
            {
                //letter is not in the trie
                traverse->children[c] = new Node();
                traverse = traverse->children[c];
                traverse->isComplete = false;
                continue;

            }
        }
        traverse->isComplete = true;
        
    }
    
    bool search(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                //letter is already in trie
                traverse = traverse->children[c];
                continue;
            }
            else
            {
                //letter is not in the trie
                return false;

            }
        }

        return (traverse->isComplete) ? true : false;
        
    }
    
    bool startsWith(string prefix) {
        Node* traverse = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            char c = prefix[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                //letter is already in trie
                traverse = traverse->children[c];
                continue;
            }
            else
            {
                //letter is not in the trie
                return false;

            }
        }
        return true;
        
    }
private:
    Node* root;
};
