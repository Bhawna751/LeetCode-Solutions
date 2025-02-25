class Solution {
public:

    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        const int MOD = 1e9+7;
        for(auto  &it:arr) it %= 2;
        vector<int> odd(n),even(n);
        if(arr[n-1] == 0) even[n-1]=1;
        else odd[n-1]=1;
        for(int i = n-2; i>= 0;i--){
            if(arr[i] == 1){
                odd[i] = (1+even[i+1]) % MOD;
                even[i] = odd[i+1]; 
            }
            else{
                even[i] = (1+even[i+1]) % MOD;
                odd[i] = odd[i+1]; 
            }
        }
        int ans=0;
        for(int it:odd){
                ans += it;
                ans %= MOD;
            }
        return ans;
    }
};