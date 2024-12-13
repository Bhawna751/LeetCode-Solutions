class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int n =nums.size();
        vector<bool> marked(n);
        vector<pair<int,int>> sorted(n);
        for(int i=0;i<n;i++){
            sorted[i] = make_pair(nums[i],i);
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            int it=sorted[i].first;
            int ind = sorted[i].second;
            if(!marked[ind]){
                ans+=it;
                marked[ind]=true;
                if(ind-1>=0)marked[ind-1]=true;
                if(ind+1<n)marked[ind+1]=true;
            }
        }
        return ans;
    }
};