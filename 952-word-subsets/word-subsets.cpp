class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq(26,0);
        for(int i = 0;i<words2.size();i++){
            vector<int> occ(26,0);
            for(int j = 0;j<words2[i].length();j++){
                int ch = words2[i][j]-'a';
                if(occ[ch]==0){
                    if(freq[ch]==0){
                        freq[ch]++;
                    }
                }
                else{
                    if(freq[ch]<occ[ch]+1){
                        freq[ch]++;
                    }
                }
                occ[ch]++;
            }
        }
        
        for(int i = 0;i<words1.size();i++){
            vector<int> store(26,0);
            for(int j = 0;j<words1[i].length();j++){
                store[words1[i][j]-'a']++;
            }
            
            bool flag = true;
            for(int k = 0;k<26;k++){
                if(freq[k]>store[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;

    }
};