class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n =s.size();
        set<string> possible;
        for(int i=0;i<s.size();i++){
            if(i+k-1<n){
                string sub = s.substr(i,k);   
                possible.insert(sub);
            }
        }
        if(possible.size() == pow(2,k)) return true;
        return false;
    }
};