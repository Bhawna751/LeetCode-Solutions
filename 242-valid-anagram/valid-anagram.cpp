class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for (char it : s) {
            freq[it]++;
        }
        for(char it: t){
            freq[it]--;
        }
        for(auto it: freq){
            int cnt = it.second;
            if(cnt!=0) return false;
        }
        return true;
    }
};