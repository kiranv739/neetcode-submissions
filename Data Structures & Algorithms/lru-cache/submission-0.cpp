class LRUCache {
public:
    class node{
        public:
        
        int key;
        int value;
        node* next;
        node* prev;

        node(int k,int v){
           key = k;
           value = v;
           next = nullptr;
           prev = nullptr;
        }
    };

    unordered_map<int,node*>m;
    node* head;
    node* tail;
    int maxsize;
    LRUCache(int capacity) {
        maxsize = capacity;
        
        head = new node(-1,-1);
        tail = new node(-1,-1);
        
        head->next = tail;
        head->prev = NULL;
        
        tail->prev = head;
        tail->next = NULL;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        else{
            MRU(m[key]);
            return m[key]->value;
        }
    }
    
    void put(int key, int val) {
        if(m.find(key)!=m.end()){
            m[key]->value = val;
            MRU(m[key]);
        }
        else{
            if(m.size()==maxsize){
                node* lru = tail->prev;
                lru->prev->next = tail;
                tail->prev = lru->prev;
                m.erase(lru->key);
                delete(lru);
            }
            m[key] = new node(key,val);
            
            m[key]->next = head->next;
            m[key]->prev = head;
            head->next->prev = m[key];
            head->next = m[key];
        }
    }
    void MRU(node* temp){
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev;

        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
    }
};
