class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) { // 3 2 1 2 1 7
        int n=nums.size();// n = 6
        int maxi=0;// maxi = 7
        int moves=0;// moves = 6
        for(int it:nums){
            maxi = max(maxi,it);
        }
        vector<int> freq(maxi+n+1,0);// 0 1 1 1 1 1 0 1 0 0 0 0 0 0 0
        for(int it:nums){
            freq[it]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]<=1)continue;
            int duplicate = freq[i]-1;// dup=2
            freq[i+1] += duplicate;//
            freq[i] = 1;
            moves += duplicate;
        }
        return moves;
    }
};