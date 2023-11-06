class LFUCache {
    int capacity;
    int minifr;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> frlist;
    unordered_map<int,list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        minifr=0;
    }
    
    int get(int key) {
        if(keyVal.find(key)==keyVal.end())return -1;
        frlist[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        frlist[keyVal[key].second].push_back(key);
        pos[key]=--frlist[keyVal[key].second].end();
        if(frlist[minifr].empty()) minifr++;
        return keyVal[key].first;
    }

    
    void put(int key, int value) {
        if(!capacity) return ;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            frlist[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            frlist[keyVal[key].second].push_back(key);
            pos[key] = --frlist[keyVal[key].second].end();
            if(frlist[minifr].empty())
                minifr++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = frlist[minifr].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            frlist[minifr].pop_front();
        }
        keyVal[key] = {value,1};
        frlist[1].push_back(key);
        pos[key] = --frlist[1].end();
        minifr = 1; 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */