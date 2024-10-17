class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> maxRight(n);
        maxRight[n-1] = n-1;
        for(int i=n-2;i>=0;i--){
            maxRight[i] = (s[i] > s[maxRight[i+1]]) ? i : maxRight[i+1];
        }
        for(int i=0;i<n;i++){
            if(s[i] < s[maxRight[i]]){
                swap(s[i], s[maxRight[i]]);
                return stoi(s);
            }
        }
        return num;
    }
};