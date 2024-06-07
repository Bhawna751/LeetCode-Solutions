class Solution {
public:
    string root(string word, unordered_set<string> dict){
        for(int i=1;i<=word.size();i++){
            string r = word.substr(0,i);
            if(dict.contains(r)){
                return r;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream s(sentence);
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        string word;
        string news;
        while(getline(s,word,' ')){
            news += root(word,dict) + " ";
        }
        news.pop_back();
        return news;
    }
};