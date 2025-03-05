class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        int add = 4;
        while(--n){
            ans += add;
            add += 4;
            
        }
        return ans;
    }
};