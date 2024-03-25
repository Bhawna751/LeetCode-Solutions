class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            pq.push(make_pair(it->second,it->first));
            if(pq.size()>(int)mpp.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;

    }
};