class Solution {
public:
    void addOne(string &s){
        int op=0;
        int n=s.length()-1;
        while(n>=0 && s[n]!='0'){ 
            s[n]='0';
            n--;            
        }
        if(n<0){
            s = '1' + s;
        }
        else{
            s[n]='1';
        }
    }
    int numSteps(string s) {
        int n= s.size();
        int op=0;
        while(s.size()>1){
            n=s.size();
            if(s[n-1] == '0') s.pop_back();//divide
            else addOne(s);
            op++;
        }
        return op;
    }
};