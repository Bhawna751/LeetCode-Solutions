class Solution {
public:
    string largestGoodInteger(string num) {
        char maxi = '\0';
        for(int i=0;i<=num.size()-3;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                maxi = max(maxi, num[i]);
            }
        }
        return maxi == '\0' ? "" : string(3,maxi);
    }
};