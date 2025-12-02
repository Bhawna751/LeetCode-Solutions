class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9+7;
        unordered_map<int,int> yFreq;
        for(int i=0;i<points.size();i++){
            int y = points[i][1];
            yFreq[y]++;
        }
        vector<long long> segments;
        for(auto it:yFreq){
            int freq = it.second;
            if(freq>=2) segments.push_back((long long)freq*(freq-1)/2);
        }
        long long ans=0;
        long long sum=0;
        for(int i=0;i<segments.size();i++){
            ans = (ans+segments[i] * sum) %mod;
            sum = (sum + segments[i]) % mod;
        }
        return (int)ans;
    }
};