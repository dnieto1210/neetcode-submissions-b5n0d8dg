struct Node{
    unordered_map<char, Node*> children;
    bool isFinished = false;
};


class PrefixTree {
public:
    PrefixTree() {
        root = new Node();
        
    }
    
    void insert(string word) {

        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                traverse = traverse->children[c];
            }
            else
            {
                Node* temp = new Node();
                traverse->children[c] = temp;
                traverse = traverse->children[c];
            }
        }

        traverse->isFinished = true;
        
    }
    
    bool search(string word) {

        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                traverse = traverse->children[c];
            }
            else
            {
                return false;
            }
        }

        return traverse->isFinished;
        
    }
    
    bool startsWith(string prefix) {

        Node* traverse = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            char c = prefix[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                traverse = traverse->children[c];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
private:
    Node* root;
};
