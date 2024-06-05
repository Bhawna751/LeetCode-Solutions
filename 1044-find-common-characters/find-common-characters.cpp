class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> common(26), current(26);
        vector<string> ans;
        for (char& ch : words[0]) {
            common[ch - 'a']++;
        }
        for (int i = 1; i < n; i++) {
            fill(current.begin(), current.end(), 0);
            for (char& ch : words[i]) {
                current[ch - 'a']++;
            }
             for (int alphabet = 0; alphabet < 26; alphabet++){
                common[alphabet] = min(common[alphabet],current[alphabet]);
            }
        }

        for (int alphabet = 0; alphabet < 26; alphabet++) {
            for (int cnt = 0; cnt < common[alphabet]; cnt++) {
                ans.push_back(string(1, alphabet + 'a'));
            }
        }
        return ans;
    }
};