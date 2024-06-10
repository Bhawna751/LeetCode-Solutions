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
    void mergeSort(vector<int> &arr,int left,int mid,int right,vector<int> &temp){
        int s1 = left,s2 = mid+1;
        int n1=mid-left+1, n2=right-mid;
        for(int i=0;i<n1;i++){
            temp[s1+i] = arr[s1+i];
        }
        for(int i=0;i<n2;i++){
            temp[s2+i] = arr[s2+i];
        }
        
    }
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> expected=heights;
        bubbleSort(expected);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(heights[i] != expected[i]) cnt++;
        }
        return cnt;
    }
};