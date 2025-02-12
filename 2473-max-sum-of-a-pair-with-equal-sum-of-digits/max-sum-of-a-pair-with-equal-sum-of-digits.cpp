class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while( n>0 ){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> pairs;
        for(int it: nums){
            int sum=digitsum(it);
            pairs.push_back({sum,it});
        }
        sort(pairs.begin(),pairs.end());
        int maxi = -1;
        for(int i=1; i < pairs.size(); i++){
            int cur = pairs[i].first;
            int prev = pairs[i-1].first;
            if(cur == prev){
                int cursum = pairs[i].second + pairs[i-1].second;
                maxi = max(maxi,cursum);
            }
        }
        return maxi;
    }
};