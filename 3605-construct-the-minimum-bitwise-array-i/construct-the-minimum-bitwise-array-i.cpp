class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int it:nums){
            int num=-1; 
            for(int i=0;i<=it;i++){
                if( (i|(i+1) ) == it) {
                    num=i;
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};