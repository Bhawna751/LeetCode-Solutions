class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,cnt2=0,ele;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
            else if(ele == nums[i])cnt++;
            else cnt--;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==ele) cnt2++;
        }
        if(cnt2 > n/2)return ele;
        return -1;
    }
};