class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(int i=0;i<allowed.length();i++){
            st.insert(allowed[i]);
        }
        int cnt = 0;
        for(string &it:words){
            bool isValid = true;
            for(int i=0;i<it.size();i++){
                if(st.find(it[i]) == st.end()){
                    isValid = false;
                    break;
                }
            }
            if(isValid)cnt++;
        }
        return cnt;
    }
};