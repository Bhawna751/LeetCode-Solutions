class Solution {
public:
    long long distributeCandies(int n, int limit) {// n= 5 limit =2
        long long ans = 0;
        for(int i=0;i<= min(limit,n);i++){ // i = 0 -> min(5,2)= 2 , i = no. of candies for each
            if(n-i > 2*limit) continue;//  4>4
            ans += min(n-i,limit) - max(0,n-i-limit) + 1;// ans = min(4,2) - max(0,5-1-2) + 1 = 2-2+1 = 1
        }
        return ans;
    }
};