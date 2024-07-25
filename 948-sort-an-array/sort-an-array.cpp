class Solution {
public:
    void bubble(vector<int> &nums){
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<i;j++){
                if(nums[j] > nums[j+1]) swap(nums[j],nums[j+1]);
            }
        }
    }
    void insertion(vector<int> &nums){
        if(nums.size()==0 || nums.size() == 1)return;
        for(int i=1;i<nums.size();i++){
            int temp = nums[i];
            int j = i-1;
            while(j>=0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
        }
    }
    void merge(vector<int> &nums, int l, int r, int m){
        vector<int> temp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while(i<=m && j<=r){
            if(nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        while(i<=m) temp[k++] = nums[i++];
        while(j<=r) temp[k++] = nums[j++];
        for(i = 0;i<k;i++) nums[l+i] = temp[i];
    }
    void msort(vector<int>&nums, int l,int r){
        if(l >= r)return;
        int m = l + (r-l)/2;
        msort(nums,l,m);
        msort(nums, m+1, r);
        merge(nums, l,r,m);
    }
    vector<int> sortArray(vector<int>& nums) {
        msort(nums, 0, nums.size()-1);
        return nums;
    }
};