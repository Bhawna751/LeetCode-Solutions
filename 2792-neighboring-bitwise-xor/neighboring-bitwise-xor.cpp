class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> original={0};
        for(int i=0;i<n;i++){
            original.push_back(derived[i]^original[i]);
        }
        bool flag0 = (original[0] == original[original.size()-1]);
        original = {1};
        for(int i=0;i<n;i++){
            original.push_back(derived[i]^original[i]);
        }
        bool flag1 = (original[0] == original[original.size()-1]);
        return flag0 | flag1;
    }
};