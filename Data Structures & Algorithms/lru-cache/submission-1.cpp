#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
};

class DoublyList {
public:
    Node* head;
    Node* tail;
    DoublyList() : head(nullptr), tail(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : max_storage(capacity), count(0) {}

    int get(int key) {
        auto it = myMap.find(key);
        if (it == myMap.end()) return -1;

        Node* node = it->second;
        moveToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        if (max_storage == 0) return; // edge case: can't store anything

        auto it = myMap.find(key);
        if (it != myMap.end()) {
            // key exists: update + mark most-recently-used
            Node* node = it->second;
            node->val = value;
            moveToTail(node);
            return;
        }

        // key does not exist: if full, evict LRU (head)
        if (count == max_storage) {
            evictHead();
            // count stays the same because we will add a new node
        } else {
            ++count;
        }

        // insert new node at tail
        Node* n = new Node(key, value);
        myMap[key] = n;
        attachToTail(n);
    }

private:
    DoublyList myList;
    unordered_map<int, Node*> myMap;
    int max_storage;
    int count;

    // Detach node from wherever it is in the list (updates head/tail safely)
    void detach(Node* node) {
        if (!node) return;

        if (node == myList.head) myList.head = node->next;
        if (node == myList.tail) myList.tail = node->prev;

        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        node->prev = nullptr;
        node->next = nullptr;
    }

    // Attach node to tail of list (handles empty list)
    void attachToTail(Node* node) {
        if (!node) return;

        if (!myList.tail) {
            myList.head = myList.tail = node;
            node->prev = node->next = nullptr;
            return;
        }

        node->prev = myList.tail;
        node->next = nullptr;
        myList.tail->next = node;
        myList.tail = node;
    }

    // Move node to tail (most recently used)
    void moveToTail(Node* node) {
        if (!node || node == myList.tail) return;
        detach(node);
        attachToTail(node);
    }

    // Remove head (least recently used)
    void evictHead() {
        Node* r = myList.head;
        if (!r) return;

        myMap.erase(r->key);
        detach(r);
        delete r;

        // If list became empty, ensure both head and tail are null
        if (!myList.head) myList.tail = nullptr;
    }
};

