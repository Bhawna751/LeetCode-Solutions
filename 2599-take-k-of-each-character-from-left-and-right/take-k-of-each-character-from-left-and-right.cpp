class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> freq(3,0);
        int n =s.length();
        for(char it:s) freq[it-'a']++;
        for(int i=0;i<3;i++){
            if(freq[i] < k)return -1;
        }
        vector<int> window(3,0);
        int l=0, maxi=0;
        for(int r=0;r<n;r++){
            window[s[r]-'a']++;
            while(l<=r && (freq[0]-window[0]<k || freq[1]-window[1]<k || freq[2]-window[2]<k)){
                window[s[l]-'a']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return n-maxi;
    }
};