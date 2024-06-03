class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
        vector<string> zigzag(numRows,"");
        int j=0, dir=-1;
        for(int i=0;i<s.length();i++){
            if(j==numRows-1 || j==0)  dir = dir * (-1);
            zigzag[j] += s[i];
            if(dir == 1) j++;
            else j--;
        } 
        string ans;
        for(auto &it : zigzag) ans+=it;
        return ans;
    }
};