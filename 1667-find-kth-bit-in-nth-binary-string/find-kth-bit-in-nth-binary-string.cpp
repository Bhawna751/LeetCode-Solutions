class Solution {
public:
    char findKthBit(int n, int k) {
        string sn = "0";
        for(int i=0;i<n && k>sn.length();i++){
            sn += '1';
            string temp=sn;
            for(int j = temp.length()-2;j>=0;j--){
                char inverted = (temp[j] == '1') ? '0':'1';
                sn += inverted;
            }
        }
        return sn[k-1];
    }
};