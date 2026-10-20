class LFUCache {
private:
    struct Node{
        int key , value , freq;
        Node * prev , * next ;
        Node(int k,int v){
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    struct DLL{
        Node * head;
        Node * tail;
        int size;

        DLL(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void add(Node * node){
            node->prev = head;
            node->next = head->next;
            head->next->prev=node;
            head->next = node;
            size++;
        }

        void remove(Node * node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node * removeLast(){
            if(size > 0){
                Node * node = tail->prev;
                remove(node);
                return node;
            }
            return nullptr;
        }
    };
    unordered_map<int,Node*> keymp;
    unordered_map<int,DLL*> freqmp;

    int capacity;
    int minfreq;
    
public :
    LFUCache(int capacity) {
        this->capacity = capacity;
        minfreq = 0;
    }

    
    int get(int key) {
        if(!keymp.count(key)) return -1;
        Node * node = keymp[key];
        update(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keymp.count(key)){
            Node * node = keymp[key];
            node->value = value;
            update(node);
            return;
        }

        if(keymp.size() == capacity){
            DLL * list = freqmp[minfreq];
            Node * removed = list->removeLast();
            keymp.erase(removed->key);
        }

        Node * node = new Node(key , value);
        keymp[key] = node;

        minfreq = 1;

        if(!freqmp.count(1)) freqmp[1] = new DLL();

        freqmp[1]->add(node);
    }

    private:

        void update(Node * node){

            int freq = node->freq;
            DLL * list = freqmp[freq];

            list->remove(node);

            if(freq == minfreq && list->size == 0){
                minfreq++;
            }

            node->freq++;

            if(!freqmp.count(node->freq)){
                freqmp[node->freq] = new DLL();
            }

            freqmp[node->freq]->add(node);
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */