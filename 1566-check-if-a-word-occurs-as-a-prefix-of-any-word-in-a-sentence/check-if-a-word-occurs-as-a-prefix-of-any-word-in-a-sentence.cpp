class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string cur;
        for(char it: sentence){
            if(it != ' ') cur += it;
            else{
                if(!cur.empty()){
                    words.push_back(cur);
                    cur = "";
                }
            }
        }
        if(!cur.empty())words.push_back(cur);
        for(int ind=0;ind<words.size();ind++){
            if(words[ind].length() >= searchWord.length()){
                bool match=true;
                for(int j=0;j<searchWord.length();j++){
                    if(words[ind][j]!=searchWord[j]){
                        match=false;
                        break;
                    }
                }
                if(match)return ind+1;
            }
        }
        return -1;
    }
};