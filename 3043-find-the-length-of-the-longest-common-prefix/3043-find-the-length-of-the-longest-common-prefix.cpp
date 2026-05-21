class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int it:arr1){
            while(!st.count(it) && it>0){
                st.insert(it);
                it =it/10;
            }
        }
        int longest=0;
        for(int it: arr2){
            while(!st.count(it) && it>0){
                it = it/10;
            }
            if(it > 0){
                longest = max(longest, static_cast<int>(log10(it) + 1));
            }
        }
        return longest;
    }
};