class Solution {
public:
    int appendCharacters(string s, string t) {
        int first=0, prefix=0;
        while(first<s.length() && prefix<t.length()){
            if(s[first] == t[prefix]){
                prefix++;
            }
            first++;
        }
        return t.length()-prefix;
    }
};