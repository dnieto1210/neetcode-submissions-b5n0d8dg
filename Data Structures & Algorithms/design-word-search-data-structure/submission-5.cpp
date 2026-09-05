struct Node{
public:
    unordered_map<char, Node*> children;
    bool isComplete = false;
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
            char c = word[i];
            if(traverse->children.find(c) == traverse->children.end())
            {
                Node* temp = new Node();
                traverse->children[c] = temp;
            }

            traverse = traverse->children[c];
        }

        traverse->isComplete = true;
        return;        
    }
    
    bool search(string word) {
        Node* traverse = root;
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if(c == '.')
            {
                bool check = false;
                for(auto kv: traverse->children)
                {
                    word[i] = kv.first;
                    bool check = search(word);
                    if(check)
                    {
                        return true;
                    }
                }

                if(check == false)
                {
                    return false;
                }

            }
            else if(traverse->children.find(c) == traverse->children.end())
            {
                return false;
            }
            else
            {
                traverse = traverse->children[c];
            }
        }

        return traverse->isComplete;
        
    }
private:
    Node* root;
};
