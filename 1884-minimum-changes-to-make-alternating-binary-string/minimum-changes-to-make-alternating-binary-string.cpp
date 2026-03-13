class Solution {
public:
    int minOperations(string s) {
        int cnt0 = 0, cnt1=0;
        int n =s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]!='0') cnt0++;
            }
            else{
                if(s[i]!='1')cnt0++;
            }
            if(i%2==0){
                if(s[i]!='1')cnt1++;
            }
            else{
                if(s[i]!='0')cnt1++;
            }
        }
        return min(cnt0,cnt1);
    }
};