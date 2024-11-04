class Solution {
public:
    string compressedString(string word) {
        string cmp="";
        int i=0;
        int n=word.length();
        while(i<n){
            int cnt = 0;
            char c = word[i];
            while(i<n && word[i] == c && cnt<9){
                i++; cnt++;
            }
            cmp += to_string(cnt) + c;
        }
        return cmp;
    }
};