struct Node{
public:
    Node* prev;
    Node* next;
    int val;
    int key;
    Node(int k, int v)
    :prev(nullptr), next(nullptr), val(v), key(k)
    {}
};

class DoublyList{
public:
    DoublyList()
    :head(nullptr), tail(nullptr), size(0)
    {}

    void addNodes(int k, int v)
    {
        Node* curr = new Node(k, v);

        if(!head)
        {
            head = curr;
            tail = head;
        }
        else
        {
            tail->next = curr;
            curr->prev = tail;
            curr->next = nullptr;
            tail = curr;
        }
        ++size;
        nodes[k] = curr;
        return;

    }

    int getSize() const
    {
        return size;
    }

    bool checkValid(int k)
    {
        if(nodes.find(k) != nodes.end())
        {
            return true;
        }
        return false;
    }

    void removeFront()
    {
        if(!head)
        {
            return;
        }

        Node* rem = head;
        
        head = head->next;
        if(head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = head;
        }
        --size;
        int k = rem->key;
        rem->next = nullptr;
        rem->prev = nullptr;
        delete rem;
        nodes.erase(k);
        return;
    }

    int getVal(int k)
    {
        if(nodes.find(k) != nodes.end())
        {
            return nodes[k]->val;
        }

        return -1;
    }

    void update(int k, int v)
    {
        Node* curr = nodes[k];
        curr->val = v;

        if(this->size == 1 || curr == tail)
        {
            return;
        }

        Node* n = curr->next;

        Node* l = curr->prev;
        Node* r = curr->next;

        if(l)
        {
            l->next = r;
        }
        if(r)
        {
            r->prev = l;
        }

        tail->next = curr;
        curr->prev = tail;
        tail = curr;
        curr->next =  nullptr;

        if(head == curr)
        {
            head = n;
        }

        return;
    }



private:
    Node* head;
    Node* tail;
    int size;
    unordered_map<int, Node*> nodes;

};





class LRUCache {
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
        myList = new DoublyList();
    }
    
    int get(int key) {
        if(myList->checkValid(key))
        {
            int v = myList->getVal(key);
            myList->update(key, v);
            return v;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(myList->checkValid(key))
        {
            myList->update(key, value);
        }
        else
        {
            myList->addNodes(key, value);
            if(myList->getSize() == cacheSize + 1)
            {
                myList->removeFront();
            }
        }
        return;
    }
private:
    int cacheSize;
    DoublyList* myList;
};
