class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>sorted(nums);
        sort(sorted.begin(),sorted.end());
        int grp=0;
        unordered_map<int,int> mpp1;
        mpp1.insert(pair<int,int>(sorted[0],grp));
        unordered_map<int,list<int>> mpp2;
        mpp2.insert(pair<int,list<int>>(grp,list<int>(1,sorted[0])));
        for(int i=1;i<nums.size();i++){
            if(abs(sorted[i] - sorted[i-1]) > limit) grp++;
            mpp1.insert(pair<int,int>(sorted[i],grp));
            if(mpp2.find(grp) == mpp2.end()) mpp2[grp] = list<int>();
            mpp2[grp].push_back(sorted[i]);
        }
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int cnt = mpp1[num];
            nums[i] = *mpp2[cnt].begin();
            mpp2[cnt].pop_front();
        }
        return nums;
    }
};