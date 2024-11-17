class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();//[77,19,35,10,-14] k = 19
        int len = 1e9;
        long long ans=0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<>> minHeap;
        for(int i=0;i<n;i++){
            ans += nums[i];// ans = 127
            if(ans >= k){
                len = min(len,i+1);//len = 1
            }
            while(!minHeap.empty() && ans-minHeap.top().first >= k){
                len=min(len,i-minHeap.top().second);
                minHeap.pop();
            }
            minHeap.emplace(ans,i);//(127,4) (131,2) 141,3
        }
        return len==1e9 ? -1: len;
    }
};