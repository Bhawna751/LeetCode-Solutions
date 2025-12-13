class Solution {
public:
    unordered_set<string> valid = {"electronics", "grocery", "pharmacy", "restaurant"};
    
    bool validCode(string &code){
        if(code=="")return false;
        for(char ch:code){
            if(!((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || ch=='_'))return false;
        }
        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string>ans;
        vector<pair<string,string>> validcodes;
        for(int i=0;i<n;i++){
            if(isActive[i] && validCode(code[i]) && valid.find(businessLine[i])!=valid.end())
                validcodes.push_back({businessLine[i],code[i]});
        }
        sort(validcodes.begin(), validcodes.end());
        for(auto &it:validcodes)ans.push_back(it.second);
        return ans;
    }
};