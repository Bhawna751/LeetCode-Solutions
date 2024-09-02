class Solution {
private:
    int bs(vector<long long> &prefix, long long remaining){
        int l = 0, h = prefix.size()-1;
        while(l < h){
            int mid = l + ( h - l )/2;
            if(prefix[mid] <= remaining) l = mid + 1;
            else h = mid;
        }
        return h;
    }
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long> prefix(n);
        prefix[0]=chalk[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + chalk[i];
        }
        long long sum = prefix[n-1];
        long long remainder = k%sum;
        
        return bs(prefix,remainder);
    }
};