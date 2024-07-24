class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mpp;//699,0  
        for(int i=0;i<nums.size();i++){
            int val = 0;// val = 699
            int temp = nums[i];// temp = 
            int unit = 1;//unit = 1000
            if(temp == 0){
                mpp.push_back({mapping[0],i});
                continue;
            }
            while(temp!=0){
                val = unit * mapping[temp%10] + val;
                unit *= 10;
                temp /=10; 
            }
            mpp.push_back({val,i});
        }
        sort(mpp.begin(), mpp.end());
        vector<int> ans;
        for(auto it: mpp){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};