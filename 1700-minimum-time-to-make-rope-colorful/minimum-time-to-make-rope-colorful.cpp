class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans=0;
        int maxi=-1e9, sum=0;
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                ans += sum - maxi;
                sum =0;
                maxi=0;
            }
            sum += neededTime[i];
            maxi = max(maxi, neededTime[i]);
        }
        return ans += sum-maxi;
    }
};