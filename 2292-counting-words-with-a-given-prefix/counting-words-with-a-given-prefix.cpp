class Solution {
public:
    int contains(string& word, string& pref){
        int i;
        for(i=0;i<word.length() && i<pref.length();i++){
            if(word[i] !=pref[i])return 0;
        }
        if(i != pref.length())return 0;
        return 1;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto it:words) ans += contains(it,pref);
        return ans;
    }
};