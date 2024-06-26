class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=k;
        for(int i=0;i<n;i++){
            ans = ans^nums[i];
           // cout<<ans<<endl;//3 2 1 5
        }
        int cnt=0;
        while(ans){//5-->2-->1
            cnt += ans & 1;//1-->1-->1+1=2
            ans>>=1;//2.5-->1-->0
        }
        return cnt;
    }
};