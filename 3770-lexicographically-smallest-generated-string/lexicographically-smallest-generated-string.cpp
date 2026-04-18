class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n+m-1,'a');
        vector<int> arr(n+m-1,0);
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=i;j<i+m;j++){
                    if(arr[j] && s[j]!=str2[j-i]) return "";
                    else{
                        s[j] = str2[j-i];
                        arr[j]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(str1[i] == 'F'){
                bool flag = false;
                int ind = -1;
                for(int j=i+m-1;j>=i;j--){
                    if(str2[j-i] != s[j]){
                        flag=true;
                    }
                    if(ind == -1 && !arr[j]) ind = j;
                }
                if(flag){
                    continue;
                }
                else if(ind != -1){
                    s[ind]='b';
                }
                else{
                    return "";
                }
            }
        }
        return s;
    }
};