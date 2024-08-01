class Solution {
public:
    int minOperations(int n) {
        int x= 1, y=1;
        if(n<=0)return 0;
        if(n==1)return 1;
        while(x*2 < n) x = x*2;// 64 / 
        y = x*2 - n;//64 - 39 = 25
        x = n-x;//39-25 = 6
        int l = minOperations(x);//6 
        int r = minOperations(y);//25 
        return min(l,r) + 1;
    }
};