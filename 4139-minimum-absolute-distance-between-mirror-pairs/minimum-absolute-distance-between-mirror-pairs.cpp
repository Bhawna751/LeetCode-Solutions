class Solution {
public:
    int reverseN(int x){
        int rev = 0;
        while(x>0){
            rev =rev*10 + (x%10);
            x= x/10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans=n+1;
        for(int i=0;i<n;i++){
            int x= nums[i];
            if(mpp.count(x)){
                ans=min(ans,i-mpp[x]);
            }
            mpp[reverseN(x)]=i;
        }
        return ans == n+1 ? -1 : ans;
    }
};