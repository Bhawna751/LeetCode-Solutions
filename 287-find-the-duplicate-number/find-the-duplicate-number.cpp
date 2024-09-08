class Solution {
public:
    int findDuplicate(vector<int>& nums) { // [3,1,3,4,2]
        int n = nums.size();
        int low = 1, high = n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            int cnt =0;
            for(int it:nums){
                if(it <= mid) cnt++; 
            }
            if(cnt>mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};