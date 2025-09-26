class Solution {
public:
    int bs(vector<int>& nums,int l, int r, int sum){
        while(r>=l && r<nums.size()){
            int mid = (l+r)/2;
            if(nums[mid] >= sum){
                r = mid-1;
            }else l=mid+1;
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            int k=i+2;
            for(int j=i+1;j<n-1 && nums[i]!=0;j++){
                k=bs(nums,k,n-1,nums[i]+nums[j]);
                ans += k-j-1;
            }
        }
        return ans;
    }
};