class Node{
public:
    int key,val;
    Node *next, *prev;
    Node(){
      key = val = -1;
      next = prev = NULL;
    }
    Node(int k, int value){
      key = k;
      val = value;
      next=prev=NULL;
    }
};

class LRUCache {
  private:
      map<int, Node*> mpp;
      int cap;
      Node *tail,*head;
      void deleteNode( Node *node){
        Node *previous=node->prev;
        Node *nextNode = node->next;
        previous-> next = nextNode;
        nextNode->prev = previous;
      }
      void insert(Node *node){
        Node *nextNode = head->next;
        head->next = node;
        nextNode -> prev = node;
        node->prev = head;
        node->next = nextNode;
      }
  public:

  LRUCache(int capacity) {
      cap = capacity;
      mpp.clear();
      head = new Node();
      tail = new Node();
      head->next = tail;
      tail->prev = head;
  }

  int get(int key_) {
    if(mpp.find(key_) == mpp.end()) return -1;
    Node *node = mpp[key_];
    int val = node->val;
    deleteNode(node);
    insert(node);
    return val;
  }

  void put(int key_, int value) {
    if(mpp.find(key_) != mpp.end()){
      Node *node = mpp[key_];
      node->val = value;
      deleteNode(node);
      insert(node);
      return;
    }
    if(mpp.size() == cap){
      Node *node = tail->prev;
      mpp.erase(node->key);
      deleteNode(node);
    }
    Node* newNode = new Node(key_, value);
		mpp[key_] = newNode;
		insert(newNode);
  }
};
