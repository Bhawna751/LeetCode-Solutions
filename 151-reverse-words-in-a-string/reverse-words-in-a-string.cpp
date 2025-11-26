class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());//"world olleh  "
        int l=0,r=0,i=0;
        int n=s.size();
        while(i<n){//i=8 r=6 l=6
            while(i<n && s[i]!=' ') {
                s[r]=s[i];
                r++;
                i++;    
            }
            if(l<r){
                reverse(s.begin()+l, s.begin()+r);
                if(r==n)break;
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        if(r>0 && s[r-1]==' ')r--;
        s.resize(r);
        return s;
    }
};