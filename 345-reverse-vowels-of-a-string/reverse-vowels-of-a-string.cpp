class Solution {
public:
    string reverseVowels(string s) {
     string ans="";
     int n = s.size();
     stack<char> vowels;
     for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U'){
            vowels.push(s[i]);
        }
     } 
     for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U'){
            ans += vowels.top();
            vowels.pop();
        }
        else ans+=s[i];
     }  
     return ans;
    }
};