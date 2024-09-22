class Solution {
public:
   
    string shortestPalindrome(string s) {
        string rev = s;//abcd
        reverse(rev.begin(),rev.end()); //dcba
        string temp = s + "#" + rev; // abcd#dcba
        vector<int> lps(temp.length(),0); // 0 1 0 0 0 0 0 0 0 
        for(int i=1;i<temp.length();i++){// i = 2
            int j = lps[i-1];// j = 1
            while(j>0 && temp[i] != temp[j]) j = lps[j-1];
            j  += (temp[i] == temp[j]);
            lps[i] = j;
        }
        int n = lps.size();
        return rev.substr(0,s.size() - lps[temp.size()-1]) + s;
    }
};