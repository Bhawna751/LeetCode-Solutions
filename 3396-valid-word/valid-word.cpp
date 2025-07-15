class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        bool hasVowel = false;
        bool hasConsonant = false;
        bool hasDigits = false;

        for (char ch : word) {
            if(ch>=48 && ch<=57) hasDigits = true;
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
            if(ch == '@' || ch=='#' || ch=='$')return false;
        }
        
        return hasVowel && hasConsonant;
    }
};