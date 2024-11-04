class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();//nums = [-1,2,1,-4], target = 1
        sort(nums.begin(), nums.end());// [-4, -1, 1, 2]  n= 4
        int ans = 1e9/2;// ans = 1e9/2
        for(int i=0;i<n-2;i++){//i=0
            int left  = i+1, right = n-1;// left = 1 right = 2
            while(left<right){
                int cur = nums[i] + nums[left] + nums[right];//cur = 
                if(abs(cur - target) < abs(ans-target)) ans = cur;// ans = 3
                if(cur < target)left++;
                else if(cur > target) right--;
                else return cur;
            }
        }
        return ans;
    }
};