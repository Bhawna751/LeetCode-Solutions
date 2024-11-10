class Solution {
public:
    void update(vector<int> &bits, int it, int cnt){
        for(int i=0;i<32;i++){
            if( (it >> i) & 1 != 0)bits[i] += cnt;
        }
    }
    int decimal(vector<int> &bits){
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits[i]!=0)ans+=pow(2,i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size(), ans = 1e9;
        vector<int> bits(32,0);
        while(j<n){
            update(bits, nums[j], 1);
            while(i<=j && decimal(bits) >= k){
                ans = min(ans, j-i+1);
                update(bits,nums[i],-1);
                i++;
            }
            j++;
        }
        if(ans == 1e9)return -1;
        return ans;
    }
};