class Solution {
public:
    void merge(vector<int>&nums, int l, int mid, int r){
        int i=l, j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;

        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int it=l;it<=r;it++){
            nums[it] = temp[it-l];
        }
    }
    void helper(vector<int>&nums, int l, int r){
        if(l>=r)return;
        int mid=(l+r)/2;
        helper(nums,l,mid);
        helper(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        helper(nums,0,n-1);
        return nums;
    }
};