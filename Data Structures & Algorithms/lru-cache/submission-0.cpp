class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int caps;
    Node* head;
    Node* tail;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node)
    {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        caps = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
            delete cache[key];
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > caps)
        {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
