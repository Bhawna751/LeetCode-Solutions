class LRUCache {
public:
    class ListNode {
        public:
            int key,val;
            ListNode *next,*prev;
            ListNode(int k,int v){
                key=k;
                val=v;
            }
    };
    ListNode *head = new ListNode(-1,-1);
    ListNode *tail = new ListNode(-1,-1);
    int c;
    unordered_map<int,ListNode*>mpp;
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void add(ListNode* node){
        ListNode* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void remove(ListNode *node){
        ListNode *temp = node->prev;
        ListNode *q = node->next;
        temp->next = q;
        q->prev = temp;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            ListNode* node = mpp[key];
            int res =node->val;
            mpp.erase(key);
            remove(node);
            add(node);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            ListNode * node = mpp[key];
            mpp.erase(key);
            remove(node);
        }
        if(mpp.size() == c){
            mpp.erase(tail->prev->key);
            remove(tail->prev);
        }
        add(new ListNode(key,value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */