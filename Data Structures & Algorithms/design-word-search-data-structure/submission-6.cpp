struct Node {
    unordered_map<char, Node*> children;
    bool isFinished = false;

};


class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c= word[i];
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
        return;
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
                if(c == '.')
                {
                    for(auto kv: traverse->children)
                    {
                        string copy = word;
                        copy[i] = kv.first;
                        if(search(copy) == true)
                        {
                            return true;
                        }
                    }

                    return false;

                }
                else
                {
                    return false;
                }
            }
        }

        return traverse->isFinished;
    }
private:
    Node* root;
};
