class ListNode {
public:
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int k, int v)
    :key(k), val(v), next(nullptr), prev(nullptr)
    {
        //na
    }
};

class DoublyList {
public:
    DoublyList()
    :head(nullptr), tail(nullptr), size(0)
    {
        //na
    }

    void insertNode(int k, int v)
    {
        ListNode* curr = new ListNode(k, v);
        ++size;
        myMap[k] = curr;
        if(!head)
        {
            head = curr;
            tail = head;
            return;
        }

        tail->next = curr;
        curr->prev = tail;
        tail = curr;
        return;
    }

    void removeFront()
    {
        if(!head)
        {
            return;
        }
        //this is to remove from our map later
        int frontKey = head->key;
        --size;
        ListNode* temp = head->next;

        head->next = nullptr;
        delete head;
        head = nullptr;
        head = temp;

        if(!head)
        {
            tail = nullptr;
        }

        //remove from map
        myMap.erase(frontKey);

        return;
    }

    void update(ListNode* node)
    {
        //this node was called 
        if(node == tail)
        {
            return; //it is already the most recently used;
        }

        if(node == head)
        {
            ListNode* temp = head->next;
            temp->prev = nullptr;

            tail->next = head;
            head->prev = tail;
            head->next = nullptr;
            tail = head;
            head = temp;
        }
        else
        {
            ListNode* before = node->prev;
            ListNode* after = node->next;
            node->prev = nullptr;
            node->next = nullptr;
            tail->next =node;
            node->prev = tail;
            tail = node;
            before->next = after;
            after->prev = before;
        }

        return;
    }

    void put(int k, int v)
    {
        if(myMap.find(k) != myMap.end())
        {
            ListNode* curr = myMap[k];
            curr->val = v;
            update(curr);
            return;
        }
        insertNode(k,v);
        return;
    }

    int get(int k)
    {
        if(myMap.find(k) == myMap.end())
        {
            return -1;
        }
        ListNode* curr = myMap[k];
        int v = curr->val;
        update(curr);
        return v;
    }

    int getSize()
    {
        return size;
    }

private:
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> myMap;
    int size;
};




class LRUCache {
public:
    LRUCache(int capacity) 
    :size(capacity)
    {
        //na
    }
    
    int get(int key) {
        int v = myList.get(key);
        return v;
    }
    
    void put(int key, int value) {
        myList.put(key, value);
        if(myList.getSize() > size)
        {
            myList.removeFront();
        }
        return;
    }
private:
    DoublyList myList;
    int size;
};
