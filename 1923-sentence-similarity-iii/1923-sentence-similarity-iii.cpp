class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n = sentence1.size(), m = sentence2.size();//
        stringstream s1(sentence1), s2(sentence2);
        string word;
        vector<string> s1wrds, s2wrds;
        while(s1 >> word) s1wrds.push_back(word);
        while(s2 >> word) s2wrds.push_back(word);
        int start = 0, end1 = s1wrds.size()-1, end2 = s2wrds.size()-1;
        if(s1wrds.size() > s2wrds.size()) return areSentencesSimilar(sentence2, sentence1);
        while(start < s1wrds.size() && s1wrds[start] == s2wrds[start]) start++;
        while(end1 >= 0 && end2 >= 0 && s1wrds[end1] == s2wrds[end2]){
            end1--;
            end2--;
        }
        return start > end1;
    }
};