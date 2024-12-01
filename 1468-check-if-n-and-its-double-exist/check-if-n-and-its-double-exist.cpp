class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> computed;
        for(int i=0;i<arr.size();i++){
           if(computed.count(2*arr[i]) || (arr[i]%2==0 && computed.count(arr[i]/2))) return true;
           computed.insert(arr[i]);
        }
        return false;
    }
};