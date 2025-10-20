class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(string it:operations){
            if(it[0]=='+' || it[2]=='+') ans++;
            else if(it[0]=='-' || it[2]=='-')ans--;
        }
        return ans;
    }
};