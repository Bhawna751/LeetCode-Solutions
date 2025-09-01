class Solution {
public:
    char kthCharacter(int k) {
        int ans=0;
        k--;
        while(k>0){
            if(k&1) ans++;
            k  = k>>1;
        }
        return (ans%26) + 'a';
    }
};