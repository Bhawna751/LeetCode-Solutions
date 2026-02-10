class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<pair<string,string>> arr;//(333333333,3)(30303030,30)(34343434,34)(555555555,5)(999999999,9)
        for(int it:nums){
            string s=to_string(it);
            string key=s;
            while(key.size()<10)key+=s;
            arr.push_back({key,s});
        }
        sort(arr.rbegin(), arr.rend());//(999999999,9)()
        string ans;
        for(auto &it:arr){
            ans += it.second;//ans += 9534330
        }
        if(ans[0]=='0')return "0";
        return ans;
    }
};