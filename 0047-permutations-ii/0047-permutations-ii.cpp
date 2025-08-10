class Solution {
public:
    void recursion(unordered_map<int,int> & freq, vector<int>& permutation, int n, vector<vector<int>> &ans){
        if(permutation.size()==n){
            ans.push_back(permutation);
            return;
        }
        for(auto it: freq){
            int num = it.first;
            int cnt = it.second;
            if(cnt==0) continue;
            permutation.push_back(num);
            freq[num]--;
            recursion(freq, permutation, n, ans);
            permutation.pop_back();
            freq[num]++; 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;
        for(int it:nums){
            freq[it]++;
        }
        vector<int> permutation ;
        recursion(freq, permutation, nums.size(), ans);
        return ans;
    }
};