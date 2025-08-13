class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(auto it: strs){
            string sorted = it;
            sort(sorted.begin(), sorted.end());
            mpp[sorted].push_back(it);
        }
        for(auto &it: mpp){
            ans.push_back(move(it.second));
        }
        return ans;
    }
};