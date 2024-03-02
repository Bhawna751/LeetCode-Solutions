class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       sort(nums.begin(),nums.end());
       int last = -1e9;
       int cnt=0;
       int longest=1;
       for(int i=0;i<n;i++) {
           if(nums[i]-1 == last){
               cnt ++;
               last = nums[i];
           }
           else if(nums[i] != last){
               cnt=1;
               last = nums[i];
           }
           longest = max(longest,cnt);
       }
       return longest;
    }
};