class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        istringstream iss(s1 + " " + s2);
        while(iss >> s1) freq[s1]++;
        vector<string> ans;
        for(auto it : freq){
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};