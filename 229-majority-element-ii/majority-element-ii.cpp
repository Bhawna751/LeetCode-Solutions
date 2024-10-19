class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();//[3,2,3,2,3,3]
        vector<int> ans;
        int mini = n/3 + 1;
        int cnt1=0,cnt2=0, ele1=-1e9, ele2=-1e9;

        for(int it: nums){
            if(cnt1 == 0 && ele2 != it){
                cnt1 = 1;
                ele1 = it;
            }
            else if(cnt2 == 0 && ele1 != it){
                cnt2 = 1;
                ele2 = it;
            }
            else if(ele1 == it) cnt1++;
            else if(ele2 == it) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }   
        cnt1 = 0, cnt2=0;
        for(int it:nums){
            if(it == ele1) cnt1++;
            if(it == ele2) cnt2++;
        }
        if(cnt1 >= mini)ans.push_back(ele1);
        if(cnt2 >= mini && ele1!=ele2) ans.push_back(ele2);
        return ans; 
    }
};