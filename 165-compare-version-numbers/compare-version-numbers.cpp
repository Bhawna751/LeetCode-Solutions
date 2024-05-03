class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.length(),m=version2.length(),i=0,j=0;
        while(i<n && j<m){
            long long n1=0,n2=0;
            while(i<n && version1[i]!='.'){
                n1 = n1*10 + version1[i]-'0';
                i++;
            }
            while(j<m && version2[j]!='.'){
                n2 = n2*10 + version2[j]-'0';
                j++;
            }
            if(n1>n2)return 1;
            else if(n1<n2) return -1;
            i++;j++;
        }
        while(i<n){
            long long n1 = 0;
            while(i<n && version1[i]!='.'){
                n1= n1*10 + version1[i]-'0';
                i++;
            }
            if(n1>0) return 1;
            i++;
        }
        while(j<m){
            long long n2 = 0;
            while(j<m && version2[j]!='.'){
                n2= n2*10 + version2[j]-'0';
                j++;
            }
            if(n2>0) return -1;
            j++;
        }
        return 0;
    }
};