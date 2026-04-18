class Trie {
private:
    struct TrieNode{
        int cnt=0, prefix=0;
        unordered_map<char,TrieNode*>children;
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char it: word){
            if(node->children.find(it)==node->children.end()){
                node->children[it] = new TrieNode();
            }
            node = node->children[it];
            node->prefix++;
        }
        node->cnt++;
    }
    
    bool search(string word) {
        TrieNode* node= root;
        for( char c:word){
            if(node->children.find(c)==node->children.end()) return false;
            node = node->children[c];
        }
        return node->cnt>0;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix){
            if(node->children.find(c)==node->children.end())return false;
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */