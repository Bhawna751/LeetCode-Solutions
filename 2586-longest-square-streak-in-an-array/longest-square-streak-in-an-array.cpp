class Solution {
public:
    bool bs(vector<int> &nums, int target){
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) r=mid-1;
            else l = mid+1;
        }
        return false;
    }

    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st;
        int longest = 0;
        for(int it: nums){
            if(st.find(it) != st.end()) continue;
            int streak=it;
            int len = 1;
            while(true){
                if((long long)streak * (long long)streak > 1e5){
                    break;
                }
                if(bs(nums, streak*streak)){
                    streak *= streak;
                    len++;
                    st.insert(streak);
                }
                else break;
            }
            longest = max(longest, len);

        }
        return (longest < 2) ? -1 : longest;
    }
};