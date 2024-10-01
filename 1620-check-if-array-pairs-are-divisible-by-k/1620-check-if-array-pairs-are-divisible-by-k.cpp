class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        //(1,2) (2,2) (3,2) (4,2) (0,2) 
        for(auto it: arr){
            mpp[(it%k + k)%k]++;
        }
        for(auto it: arr){
            int rem = (it % k + k )%k;
            if(rem == 0){
                if(mpp[rem] % 2 == 1) return false;
            }
            else if(mpp[rem] != mpp[k-rem]) return false;
        }
        return true;
    }
};