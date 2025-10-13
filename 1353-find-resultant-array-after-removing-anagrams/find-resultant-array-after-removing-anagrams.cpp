class Solution {
public:
    bool valid(string a, string b){
        vector<int>freq(26);
        for(char ch:a)freq[ch-'a']++;
        for(char ch:b)freq[ch-'a']--;
        for(int it:freq){
            if(it!=0)return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n && valid(words[i], words[j])) j++;
            ans.push_back(words[i]);
            i=j;
        }
        return ans;
    }
};