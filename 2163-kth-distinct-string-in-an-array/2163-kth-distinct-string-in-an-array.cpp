class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(auto it: arr) freq[it]++;
        for(auto it: arr){
            if(freq[it] == 1) k--;
            if(k==0) return it;
        }
        return "";
    }
};