class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<pair<int,int>> mindq;
        deque<pair<int,int>> maxdq;
        int ans=0,l=0,r=0;
        while(r<n){
            while(!mindq.empty() && mindq.back().first > nums[r]) mindq.pop_back();
            mindq.push_back({nums[r],r});

            while(!maxdq.empty() && maxdq.back().first < nums[r]) maxdq.pop_back();
            maxdq.push_back({nums[r],r});

            int diff = maxdq.front().first - mindq.front().first;

            while(l<r && diff>limit){
                l =min( maxdq.front().second,mindq.front().second) + 1;
                while( !maxdq.empty() && maxdq.front().second<l) maxdq.pop_front();
                while( !mindq.empty() && mindq.front().second<l) mindq.pop_front();
                diff = maxdq.front().first - mindq.front().first;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};