class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m=needle.size();
        for(int i=0;;i++){
            for(int j=0;;j++){
                if(j == m)return i;
                if(i+j==n)return -1;
                if(haystack[i+j]!=needle[j])break;
                
            }
        }
    }
};