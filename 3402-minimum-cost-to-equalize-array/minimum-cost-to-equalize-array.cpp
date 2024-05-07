const int M=1e6;
const int MOD = 1e9+7;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        vector<int> req(M+1,0);
        int n = nums.size();
        int mx = 0;
        long long sum =0;
        for(auto i : nums) mx = max(mx,i);
        for(auto i : nums){
            req[mx-i]++;
            sum += mx-i;
        }
        long long l=M,r=M;
        long long ans = sum *cost1;
        long long ops=0;

        while(l>0 && r>0){
            while(r>0 && req[r]==0)r--;
            if(r==0)break;

            while(l>0){
                if(r==l){
                    if(req[l]>1)break;
                    l--;
                    continue;
                }
                if(req[l]>0)break;
                l--;
            }
            if(l==0){
                assert(req[r]==1);
                ans = min(ans,ops + r*cost1);
                if(n==2)break;
                if(r==1 && (n%2==0))break;
                ops += cost2;
                req[1] += n-2;
                l=1;
                continue;
            }
            long long can=0;
            if(l==r) can = req[l]/2;
            else can = 1;

            ops+= can*cost2;
            req[r] -= can;
            req[r-1]+= can;
            req[l] -= can;
            req[l-1] += can;
        }
        ans = min(ans,ops+r*cost1);
        return ans % MOD;
    }
};