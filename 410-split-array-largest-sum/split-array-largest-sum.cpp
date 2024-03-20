class Solution {
public:
    int countStud(vector<int> &nums,int mid){
        int n=nums.size();
        int students = 1;
        long long page = 0;
        for(int i=0;i<n;i++){
            if(page + nums[i]<=mid) page+= nums[i];
            else{
                students++;
                page = nums[i];
            }        
        }
        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int students = countStud(nums,mid);
            if(students > k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};