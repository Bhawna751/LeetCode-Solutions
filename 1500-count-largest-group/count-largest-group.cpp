class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int sum = 0, tens  =i;
            while(tens){
                sum += tens % 10;
                tens = tens/10;
            }
            mpp[sum]++;
            maxi = max(maxi,mpp[sum]);
        }
        int cnt=0;
        for(auto it: mpp){
            if(it.second == maxi) cnt++;
        }
        return cnt;
    }
};