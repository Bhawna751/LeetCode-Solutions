class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        unordered_set<string> hashset(wordList.begin(), wordList.end());
        hashset.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(char c = 'a';c<='z';c++ ){
                    word[i] = c;
                    if(hashset.find(word) != hashset.end()){
                        hashset.erase(word);
                        q.push({word, step+1});
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};