class Solution {  
public:
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+helper(1,1,n);
    }
    int helper(int cur,int paste,int n){
        if(cur == n) return 0;
        if(cur>n) return 1000;
        int op1 = 2 + helper(cur*2, cur,n);
        int op2 = 1 + helper(cur+paste, paste,n);
        return min(op1,op2);
    }
};