class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result,remaining;
        unordered_map<int,int> mpp;
        for(int i=0;i<arr2.size();i++){
            mpp[arr2[i]] = 0;
        }
        for(int i=0;i<arr1.size();i++){
            if(mpp.find(arr1[i]) != mpp.end()) mpp[arr1[i]]++;
            else remaining.push_back(arr1[i]);
        }
        sort(remaining.begin(),remaining.end());
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<mpp[arr2[i]];j++){
                result.push_back(arr2[i]);
            }
        }
        for (int i = 0; i < remaining.size(); i++) {
            result.push_back(remaining[i]);
        }
        return result;
    }
};