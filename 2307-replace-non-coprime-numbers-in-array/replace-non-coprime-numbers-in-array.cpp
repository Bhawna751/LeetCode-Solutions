class Solution {
public:
    // long long lcm (long long a, long long b){
    //     long long maxi = max(a,b);
    //     long long mini = min(a,b);
    //     for(long long i= maxi;i<= a*b; i+= maxi){
    //         if(i % mini == 0)return i;
    //     }
    //     return 1;
    // }
    // int gcd(int a, int b){
    //     int ans = min(a,b);
    //     while(ans>1){
    //         if(a%ans == 0 && b%ans==0) break;
    //         ans--;
    //     }
    //     return ans;
    // }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int j=0;
        for(int i=0;i<nums.size(); i++, j++){
            nums[j] = nums[i];
            for(; j >= 1 && gcd(nums[j], nums[j-1]) > 1; j--){
                nums[j-1] = (long long)nums[j]*nums[j-1] /gcd(nums[j], nums[j-1]);
            }
        }
        nums.resize(j);
        return nums;
    }
};