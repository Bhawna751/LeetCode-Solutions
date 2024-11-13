class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), cnt=0;
        sort(nums.begin(), nums.end());//-1,1,1,2,3
        for(int i=0;i<n-1;i++){
            int low = i+1, high = n-1;// low = 1, high = 4
            int ans = i;//ans = 0
            int rem = target - nums[i];// rem = 3
            while(low<=high){
                int mid = (low+high)/2;// mid = 4
                if(nums[mid] < rem){
                    low = mid + 1;//low = 4
                    ans = max(ans,mid);//ans = 3
                }
                else high = mid-1;
            }
            cnt += ans-i;
        }
        return cnt;
    }
};