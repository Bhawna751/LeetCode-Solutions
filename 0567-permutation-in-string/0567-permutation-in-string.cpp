class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        vector<int>freq1(26,0), freq2(26,0);
        for(auto c: s1){
            freq1[c-'a']++; // 1 1 
        }
       int i=0,j=0,c=0;//i = 4, j = 4
       while(i<m){
            freq2[s2[i] - 'a']++;//1 1 _ 0 0 _ _ _ 0 _ _ _ _ _ 0
            if(i >= n) freq2[s2[j++] - 'a']--;
            if(freq1==freq2) return true;
            i++;
       }
       return false;
    }
};