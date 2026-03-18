class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(), m = s.size();
        map<char,string>mpp1;
        map<string,char>mpp2;
        int ind1=0, ind2=0;
        
        while(ind1<n && ind2 < m){
            string temp="";
            while(ind2 < m && s[ind2]==' '){
                ind2++;
            }
            while(ind2 < m && s[ind2] != ' '){
                temp += s[ind2];
                ind2++;
            }
            if(mpp1.count(pattern[ind1])){
                if(mpp1[pattern[ind1]] != temp) return 0;
            }
            else mpp1[pattern[ind1]] = temp;
            if(mpp2.count(temp)){
                if(mpp2[temp]!=pattern[ind1]) return 0;
            }else{
                mpp2[temp] = pattern[ind1];
            }
            ind1++;
        }
        if((ind1 == n && ind2 != m)||(ind1!=n && ind2 ==m)) return 0;
        return 1;
    }
};