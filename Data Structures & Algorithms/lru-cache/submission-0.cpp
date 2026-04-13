struct ListNode
    {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v)
        {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }

    };



class Doubly{
    public:
    Doubly()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insert(int k, int v)
    {
        ListNode* node = new ListNode(k, v);
        if(!head)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void remove(ListNode* node)
    {
        if(!node)
        {
            return;
        }
        else
        {
            if(node == head)
            {
                head = node->next;
            }
            if(node == tail)
            {
                tail = node->prev;
            }
        }

        if(node->prev)
        {
            ListNode* p = node->prev;
            p->next = node->next;
        }

        if(node->next)
        {
            ListNode* n = node->next;
            n->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = nullptr;
        delete node;

    }

    ListNode* getFront() const
    {
        return head;
    }

    ListNode* getBack() const
    {
        return tail;
    }




    private:
    ListNode* head;
    ListNode* tail;
};



class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        
    }
    
    int get(int key) {
        if(myMap.find(key) != myMap.end())
        {
            //key exists
            ListNode* temp = myMap[key];
            int temp_key = temp->key;
            int temp_val = temp->val;
            myList.remove(temp);
            myList.insert(temp_key, temp_val);
            return temp_val;
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(myMap.find(key) != myMap.end())
        {
            //key already exists;
            myList.remove(myMap[key]);
            myList.insert(key, value);
            myMap[key] = myList.getBack();
        }
        else
        {
            //it does not exist
            myList.insert(key, value);
            myMap[key] = myList.getBack();

            if(myMap.size() > cap)
            {
                //we have to remove LRU
                ListNode* f = myList.getFront();
                int key_to_node = f->key;
                myMap.erase(key_to_node);
                myList.remove(f);
            }
        }
        
    }
private:
    Doubly myList;
    std::unordered_map<int, ListNode*> myMap;
    int cap;
};
