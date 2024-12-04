class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int ind2=0, n=str1.length(), m=str2.length();
        for(int ind1=0;ind1<n && ind2<m;ind1++){
            if(str1[ind1]==str2[ind2] || (str1[ind1]+1 == str2[ind2]) || (str1[ind1]-25 == str2[ind2])){
                ind2++;
            }
        }
        return ind2 == m;
    }
};