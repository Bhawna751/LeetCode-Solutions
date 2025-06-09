class Solution {
public:
    int count (int n, long pre1, long pre2){
        int step = 0;
        while(pre1<=n){
            step += min((long)(n+1), pre2) -pre1;
            pre1 *= 10;
            pre2 *= 10;
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k>0){
            int step = count (n,cur,cur+1);
            if(step <= k){
                cur++;
                k = k-step;
            }
            else{
                cur =cur*10;
                k--;
            }
        }
        return cur;
    }
};