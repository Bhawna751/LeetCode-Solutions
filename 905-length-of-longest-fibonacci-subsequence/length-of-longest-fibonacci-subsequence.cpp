class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st(arr.begin(),arr.end());
        int n = arr.size();
        int len=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prev = arr[j];
                int cur = arr[i] + arr[j];
                int size=2;
                while(st.find(cur) != st.end()){
                    int temp = cur;
                    cur += prev;
                    prev = temp;
                    len = max(len, ++size);
                }
            }
        }
        return len;
    }
};