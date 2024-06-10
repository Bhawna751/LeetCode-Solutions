class Solution {
public:
    void bubbleSort(vector<int> &arr){
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
   
    
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> expected=heights;
       sort(expected.begin(),expected.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(heights[i] != expected[i]) cnt++;
        }
        return cnt;
    }
};