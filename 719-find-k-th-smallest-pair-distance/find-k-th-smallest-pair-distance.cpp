class Solution {
public:
    int count(vector<int>&nums, vector<int>&prefix, unordered_map<int,int>&mpp, int dist){
        int cnt = 0;
        int n = nums.size();
        int ind =0;
        while(ind < n){
            int cur = nums[ind];
            int valueCnt = mpp.at(cur);
            int large = prefix[cur + dist] - prefix[cur];
            int same = valueCnt * (valueCnt - 1)/2;
            cnt += large * valueCnt + same;
            while(ind + 1<n && nums[ind] == nums[ind + 1])++ind;
            ++ind;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi = nums[n-1];
        int dist = maxi*2;
        vector<int> prefix(dist,0);
        unordered_map<int,int> mpp;
        int ind=0;
        for(int i = 0;i<dist;i++){
            while(ind < n && nums[ind]<=i) ind++;
            prefix[i] = ind;
        }
        for(int i=0;i<n;i++) ++mpp[nums[i]];
        int low =0 ,high = maxi;
        while(low<high){
            int mid = (low+high)/2;
            int cnt = count(nums,prefix,mpp,mid);
            if(cnt<k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};