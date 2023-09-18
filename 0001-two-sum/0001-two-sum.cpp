class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int a[n];
        
     for(int i=0;i<nums.size();i++){
         a[i]=nums[i];
     }
        vector<int>v;
        sort(nums.begin(),nums.end());
               int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
              
             break;
            }
            else if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                l++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[l]==a[i]){
                v.push_back(i);
            }
            else if(nums[r]==a[i]){
                v.push_back(i);
            }
        }
        
        return v;
    }
};