class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        vector<int>prefix (n);
        prefix[0]=((int)(s[0]-'0')) == 1 ? 1:0;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1] + (s[i]-'0' == 1 ? 1:0);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int one = 0, zero=0;
            for(int j=i;j<n;j++){
                one = prefix[j]-(i==0 ? 0:prefix[i-1]);
                zero = (j-i+1)-one;
                if(zero*zero > one){
                    j+= zero*zero-one-1;
                }else if(zero*zero==one)ans++;
                else if(zero*zero<one){
                    ans++;
                    int diff=sqrt(one) - zero;
                    int next=j+diff;
                    if(next>=n) ans+=(n-j-1);
                    else ans+=diff;
                    j=next;
                }
            }
        }
        return ans;
    }
};