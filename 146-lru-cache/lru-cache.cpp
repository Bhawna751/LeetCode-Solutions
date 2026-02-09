class Node{
public:
    int key, val;
    Node *next, *prev;
    Node(){
        key = -1;
        val = -1;
        next = nullptr;
        prev = nullptr;

    }
    Node(int k, int value){
        key = k;
        val= value;
        next=prev=nullptr;
    }
};
class LRUCache {
public:
    map<int,Node*> mpp;
    int cap;
    Node *head, *tail;
    void deleteNode(Node* node){
        Node* p=node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }
    void insertNode(Node* node){
        Node *n=head->next;
        head->next = node;
        n->prev = node;
        node->prev = head;
        node->next = n;
    }
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node *node = mpp[key];
        int val =node->val;
        deleteNode(node);
        insertNode(node);
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node *node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertNode(node);
            return;
        }

        if(mpp.size()==cap){
            Node *node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        Node* n=new Node(key,value);
        mpp[key]=n;
        insertNode(n);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */