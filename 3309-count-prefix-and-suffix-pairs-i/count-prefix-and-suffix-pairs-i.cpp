class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string &s1 = words[i], &s2 = words[j];
                if(s1.size() > s2.size()) continue;
                if(s2.find(s1) == 0 && s2.rfind(s1) == s2.size()-s1.size()) ans++;
            }
        }
        return ans;
    }
};