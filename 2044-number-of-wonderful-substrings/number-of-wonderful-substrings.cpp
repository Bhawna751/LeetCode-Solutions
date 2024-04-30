class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.length();
        long long total=0, is_odd=0;
        unordered_map<long long, int> mpp;
        mpp[is_odd] +=1;
        for(auto c:word){
            int d = c - 'a';
            is_odd = is_odd^(1<<d);
            total += mpp[is_odd];
            for(int i=0;i<10;i++){
                is_odd = is_odd^(1<<i);
                total += mpp[is_odd];
                is_odd = is_odd^(1<<i);
            }
            mpp[is_odd]+=1;
        }
        return total;
    }
};