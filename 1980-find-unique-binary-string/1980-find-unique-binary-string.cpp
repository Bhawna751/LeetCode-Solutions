class Solution {
public:
    int n;
    unordered_set<string>st;

    string generate(string cur){
        if(cur.size() == n){
            if(st.find(cur) == st.end()) return cur;
            return "";
        }
        string zero = generate(cur+ "0");
        if(zero.size() > 0) return zero;
        return generate(cur+ "1");
    } 

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(string ch:nums){
            st.insert(ch);
        }
        return generate("");
    }
};