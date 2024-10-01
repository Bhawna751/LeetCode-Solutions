class Node{
public:
    int freq;
    Node *prev, *next;
    unordered_set<string> st;
    Node(int freq) : freq(freq), prev(nullptr), next(nullptr){}
};
class AllOne {
private:
    Node *head, *tail;
    unordered_map<string, Node*> mpp;
    void removeNode(Node *node){
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mpp.find(key) != mpp.end()){
            Node *node = mpp[key];
            int freq = node->freq;
            node->st.erase(key);
            Node *next = node->next;
            if(next == tail || next->freq != freq+1){
                Node *newnode = new Node(freq+1);
                newnode->st.insert(key);
                newnode->prev = node;
                newnode->next = next;
                node->next = newnode;
                next->prev = newnode;
                mpp[key] = newnode;
            }
            else{
                next->st.insert(key);
                mpp[key] = next;
            }
            if(node->st.empty()) removeNode(node);
        }else{
            Node *first = head->next;
            if(first ==tail || first->freq > 1){
                Node *newnode = new Node(1);
                newnode->st.insert(key);
                newnode->prev = head;
                newnode->next = first;
                head->next = newnode;
                first->prev = newnode;
                mpp[key] = newnode;
            }else{
                first->st.insert(key);
                mpp[key] = first;
            }
        }
    }
    
    void dec(string key) {
        if(mpp.find(key) == mpp.end()){ return;}
        Node *node = mpp[key];
        node->st.erase(key);
        int freq = node->freq;
        if(freq == 1) mpp.erase(key);
        else{
            Node *prevNode = node->prev;
            if(prevNode == head || prevNode->freq != freq-1){
                Node *newnode = new Node(freq-1);
                newnode->st.insert(key);
                newnode->prev = prevNode;
                newnode->next = node;
                prevNode->next = newnode;
                node->prev = newnode;
                mpp[key] = newnode; 
            }else{
                prevNode->st.insert(key);
                mpp[key] = prevNode;
            }
        }
        if(node->st.empty()) removeNode(node);
    }
    
    string getMaxKey() {
        if(tail->prev == head) return "";
        return *(tail->prev->st.begin());
    }
    
    string getMinKey() {
        if(head->next == tail) return "";
        return *(head->next->st.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */