class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int ans=0, sum = accumulate(nums.begin(), nums.end(),0);
        int left = 0, right = sum;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(left-right >=0 && left-right <= 1) ans++;
                if(right-left >=0 && right-left <=1)ans++;
            }
            else{
                left += nums[i];
                right -= nums[i];
            }
        }   
        return ans;
    }
};