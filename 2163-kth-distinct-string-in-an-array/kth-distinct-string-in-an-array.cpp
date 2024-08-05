class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> dis;
        unordered_set<string> dup;
        for(auto it: arr){
            if(dup.count(it)) continue;
            if(dis.count(it)){
                dis.erase(it);
                dup.insert(it);
            }else dis.insert(it);
        }
        for(auto it: arr){
            if(!dup.count(it)) k--;
            if(k == 0) return it;
        }
        return "";
    }
};