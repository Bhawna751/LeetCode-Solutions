class NumberContainers {
public:
    unordered_map<int,int> posToNum;
    unordered_map<int,set<int>> numToPos;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(posToNum.find(index) != posToNum.end()){
            int prev = posToNum[index];
            numToPos[prev].erase(index);
            if(numToPos[prev].empty()) numToPos.erase(prev);
        }
        posToNum[index]=number;
        numToPos[number].insert(index);
    }
    
    int find(int number) {
        if(numToPos.find(number)!=numToPos.end()) return *numToPos[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */