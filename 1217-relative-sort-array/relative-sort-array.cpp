class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi= *max_element(arr1.begin(),arr1.end());//maxi = 19
        vector<int> freq(maxi+1);//_ 1 3 2 1 _ 1 1 _ 1 ______ 1
        for(int it:arr1){
            freq[it]++;
        }
        vector<int> result;
        for(int it:arr2){
            while(freq[it]>0){
                result.push_back(it);//result-> 2 2 2 1 4 3 3 9 6 
                freq[it]--;
            }
        }
        for(int i= 0;i<=maxi;i++){
            while(freq[i]>0){
                result.push_back(i);
                freq[i]--;
            }
        }
        return result;
    }
};