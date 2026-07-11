class LRUCache {
public:
    // DLL class
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key = k, val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    // map <key, node>
    unordered_map<int, Node*> mp;

    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    // add in front of DLL
    void addNode(Node* node){
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    // delete from back of DLL
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;

        // extract node from map
        Node* node = mp[key];
        int value = node->val;

        // delete the node then add in front
        deleteNode(node);
        addNode(node);

        return value;
    }

    void put(int key, int value) {
        // if already present then delete and add
        if(mp.count(key)){
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        // if out of capacity delete LRU node
        if(mp.size() == cap){
            Node* LRU = tail->prev;
            mp.erase(LRU->key);
            deleteNode(LRU); 
        }
        // add node in front
        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */