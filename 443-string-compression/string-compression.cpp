class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ans=0;
        for(int i =0;i<n;){
            char cur = chars[i];
            int cnt=0;
            while(i<n && cur==chars[i]){
                i++;
                cnt++;
            }
            chars[ans]=cur;
            ans++;
            if(cnt>1){
                for(char c:to_string(cnt)){
                    chars[ans]=c;
                    ans++;
                }
            }
        }
        return ans;
    }
};