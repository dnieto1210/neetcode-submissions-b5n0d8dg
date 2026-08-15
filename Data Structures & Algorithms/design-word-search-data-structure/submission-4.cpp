struct Node{
    unordered_map<char, Node*> children;
    bool isComplete = false;
};


class WordDictionary {
public:
    WordDictionary() {
        root= new Node();
        
    }
    
    void addWord(string word) {
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

        //traverse->children['*'] = nullptr;
        traverse->isComplete = true;
        
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
                        //Node* second = kv.second;
                        char love = kv.first;
                        word[i] = love;
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

        return traverse->isComplete;
        
    }
private:
    Node* root;
};
