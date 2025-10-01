class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        if(k==nums.size())return nums;
        for(int it:nums) mpp[it]++;
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > mpp.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};