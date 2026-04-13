struct Node{
    std::unordered_map<char, Node*> children;
    bool isWord;
};



class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
        root->isWord = false;
    }
    
    void addWord(string word) {
        Node* traverse = root;

        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                //letter exists
                traverse = traverse->children[c];
                continue;
            }
            else
            {
                //letter does not exist
                Node* temp = new Node();
                temp->isWord = false;
                traverse->children[c] = temp;
                traverse = traverse->children[c];
            }
        }

        traverse->isWord = true;
        
    }
    
    bool search(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(traverse->children.find(c) != traverse->children.end())
            {
                traverse = traverse->children[c];
                continue;
            }
            else
            {
                if(c == '.')
                {
                    for(auto k : traverse->children)
                    {
                        word[i] = k.first;
                        if(search(word))
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
        return traverse->isWord;
    }
private:
    Node* root;
};
