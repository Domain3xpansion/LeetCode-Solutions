class LRUCache{
    private:
        class Node{
            public:
                int key, value;
                Node* prev;
                Node* next;
                Node(int k, int v){
                    key = k;
                    value = v;
                    prev = nullptr;
                    next = nullptr;
                }
        };

        int capacity;
        map<int, Node*> mp;
        Node* head;
        Node* tail;
        void removeNode(Node* node){                // Remove node from DLL
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        void insertFront(Node* node){                 // Insert node right after head (MRU)
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;
        }
        void moveToFront(Node* node){               // Move node to MRU position
            removeNode(node);
            insertFront(node);
        }
    public:
        LRUCache(int capacity){
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key){
            if(mp.find(key) == mp.end())
                return -1;
            Node* node = mp[key];
            moveToFront(node);
            return node->value;
        }
        
        void put(int key, int value){
            if(mp.find(key) != mp.end()){         // Key already exists: update and mark as MRU
                Node* node = mp[key];
                node->value = value;
                moveToFront(node);
                return;
            }

            if (mp.size() == capacity){          // Evict LRU if cache is full
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            
            Node* node = new Node(key, value);           // Insert new node
            mp[key] = node;
            insertFront(node);
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */