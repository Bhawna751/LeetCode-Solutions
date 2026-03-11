class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0,power=1;
        while(n!=0){
            if(n%2==0) ans += power;
            power *= 2;
            n=n/2;
        }
        return ans;
    }
};