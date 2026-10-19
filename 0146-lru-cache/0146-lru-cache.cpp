class LRUCache {
    struct Node{
        int key, val;
        Node * next , * prev;
        Node(int k,int v){
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };
    unordered_map<int,Node *> mp;
    int cap;
    Node * head,* tail;

    void remove(Node * node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add_front(Node * node){
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    };
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node * node = mp[key];
        remove(node);
        add_front(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node * node = mp[key];
            node->val = value;
            remove(node);
            add_front(node);
        }
        else{
            if(cap == mp.size()){
                Node * lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node * node = new Node(key , value);
            mp[key] = node;
            add_front(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */