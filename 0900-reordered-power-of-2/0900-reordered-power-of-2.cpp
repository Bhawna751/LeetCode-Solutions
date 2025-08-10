class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        for(int i=0;i<30;i++){
            int shift = 1 << i;
            string s = to_string(shift);
            sort(s.begin(), s.end());
            if(num == s) return true;
        }
        return false;
    }
};