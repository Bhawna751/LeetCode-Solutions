class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++){
            string str = to_string(i);
            int len=str.length();
            if(len%2!=0)continue;
            int k = len/2;
            int left = 0, right=0;
            for(int j=0;j<k;j++){
                left += str[j] - '0'; 
            }
            for(int j=k;j<len;j++){
                right += str[j] - '0'; 
            }
            if(left == right) ans++;
        }
        return ans;
    }
};