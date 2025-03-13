class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        int sum = 0,k=0;
        vector<int>diff(n+1);
        for(int i=0;i<n;i++){
            while(sum+diff[i] < nums[i]){
                k++;
                if(k>queries.size()) return -1;
                int l = queries[k-1][0], r=queries[k-1][1], val=queries[k-1][2];
                if(r >= i){
                    diff[max(l,i)] += val;
                    diff[r+1] -= val;
                }
            }
                sum += diff[i];
        }
        return k;
    }
};