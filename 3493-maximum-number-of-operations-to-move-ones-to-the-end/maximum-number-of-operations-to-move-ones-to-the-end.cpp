class Solution {
public:
    int maxOperations(string s) {
        int n =s.size();
        int ones=0, ans=0,i=0;
        int prev=-1;
        for(char c:s){
            int bit = c-'0';
            ones += bit;
            if(bit==0 && prev==1) ans += ones;
            prev=bit;
        }
        return ans;
    }
};