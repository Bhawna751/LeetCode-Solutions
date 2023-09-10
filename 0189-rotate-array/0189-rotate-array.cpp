class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length=nums.size();
        vector<int>t(length);
        for(int i = 0;i<length;i++){
            t[(i+k)%length]=nums[i];
        }
        nums=t;
    }
};