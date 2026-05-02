class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=2;i<=n;i++){
            string s = to_string(i);
            bool valid = true;
            bool diff = false;
            for(char it:s){
                if(it=='3' || it=='4' || it=='7'){
                    valid = false;
                    break;
                }
                if(it=='2' || it=='5' || it=='6' || it=='9'){
                    diff = true;
                }
            }
            if(valid && diff) ans++;
        }
        return ans++;
    }
};