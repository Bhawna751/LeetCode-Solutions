class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x){
            int temp=x%10;
            x=x/10;
            if((ans>0&&ans>(INT_MAX-x)/10)|(ans<0&&ans<(INT_MIN-x)/10))   return 0;
            ans = ans*10+temp;
        }
        return ans;
    }
};