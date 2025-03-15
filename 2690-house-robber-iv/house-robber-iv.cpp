class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mini=1, maxi=*max_element(nums.begin(),nums.end()), n = nums.size();
        while(mini < maxi){
            int mid = (mini+maxi)/2;
            int possible=0;
            for(int i=0;i<n;i++){
                if(nums[i] <= mid){
                    possible += 1;
                    i++;
                }
            }
            if(possible >= k) maxi = mid;
            else mini = mid+1;
        }
        return mini;
    }
};