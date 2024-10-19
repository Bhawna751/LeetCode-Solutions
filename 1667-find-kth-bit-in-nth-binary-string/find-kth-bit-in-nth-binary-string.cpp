class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int bits = pow(2,n);
        if(bits/2 > k) return findKthBit(n-1,k);
        else if(bits/2 == k) return '1';
        else{
            char bit = findKthBit(n-1,bits-k);
            return (bit == '0') ? '1':'0';
        }
        
    }
};