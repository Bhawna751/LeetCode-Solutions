class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans(n);
        unordered_set<char> vowels{'a','e','i','o','u'};
        vector<int> prefix(words.size());
        int sum=0;
        for(int i=0;i<words.size();i++){
            string cur = words[i];
            if(vowels.count(cur[0]) && vowels.count(cur[cur.size()-1])) sum++;
            prefix[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            vector<int> cur=queries[i];
            ans[i] = prefix[cur[1]] - (cur[0] == 0 ? 0 : prefix[cur[0] - 1]);
        }
        return ans;
    }
};