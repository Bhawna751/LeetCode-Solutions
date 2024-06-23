class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0,l = 0,r=0;//8 2 4 7 
        int n=nums.size();//n = 4
        multiset<int> st;
        while(r<n){// 3 < 4
            st.insert(nums[r]);// 4 7 8 
            int diff = *st.rbegin() - *st.begin();// diff = 8-4 = 4
            if(diff>limit && l<r){//  6 > 4   &&   0 < 1 
                auto num = st.find(nums[l]);// num = 2
                st.erase(num);
                l++;// l = 1
                diff = *st.rbegin() - *st.begin();// diff = 0
            }
            ans = max(ans,(int)st.size());// ans = 2
            r++;
        }
        return ans;
    }
};