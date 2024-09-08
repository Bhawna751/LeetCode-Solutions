class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int mini = int (n/3) +1;
        int cnt1 = 0, cnt2 = 0, ele1 = -1e9, ele2 = -1e9;

        for(int i=0;i<n;i++){
            if(cnt1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                cnt1++;
            }else if(cnt2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                cnt2++;
            }
            else if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--; cnt2--;
            }
        }
        cnt1 = 0; cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini && ele1 != ele2) ans.push_back(ele2);
        return ans;
    }
};