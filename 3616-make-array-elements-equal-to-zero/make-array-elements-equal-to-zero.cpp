class Solution {
public:
    bool valid(const vector<int>&nums, int dir, int ind,int nz){
        
        vector<int>temp = nums;
        
        while(nz > 0 && ind >=0 && ind < nums.size()){
            if(temp[ind] > 0){
                temp[ind]--;
                dir = -dir;
                if(temp[ind] == 0)nz--;
            }
            ind += dir;
        }
        return nz == 0;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans=0,nz=0;
        for(int it:nums)if(it>0)nz++;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(valid(nums,1,i,nz)) ans++;
                if (valid(nums,-1,i,nz)) ans++;
            }
        }
        return ans;
    }
};