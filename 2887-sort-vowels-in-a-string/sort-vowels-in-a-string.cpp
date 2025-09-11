class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' 
                || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        string t=s;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' 
                || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                t[i] = vowels[j];
                j++;
            }
        }
        return t;
    }
};