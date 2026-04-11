class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1,-1), q(n+1,-1);
        int mini= 1e9;
        for(int i=0;i<n;i++){
            int it=nums[i];
            if(q[it]!=-1){
                int dist = i-q[it];
                mini = min(dist, mini);

            }
            q[it] = p[it];
            p[it] = i;
        }
        return mini == 1e9 ? -1 : 2*mini;
    }
};