class Solution {
public:
    bool match(string &next, string &pattern){
        for(int i=0;i<pattern.size();i++){
            if(pattern[i] == 'I'){
                if(next[i] > next[i+1]) return false;
            }
            else{
                if(next[i] < next[i+1]) return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int n=pattern.length();
        string ans="";
        for(int i=1;i<=n+1;i++){
            ans.push_back(i+'0');
        }
        string next = ans;
        while(!match(next,pattern)){
            next_permutation(next.begin(),next.end());
        }
        return next;
    }
};