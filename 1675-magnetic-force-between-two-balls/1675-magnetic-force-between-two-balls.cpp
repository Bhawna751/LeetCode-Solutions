class Solution {
public:
    bool place(vector<int>& position, int x, int m){
        int prev = position[0];
        int placed = 1;
        for(int i=1;i<position.size() && placed<m;i++){
            int cur = position[i];
            if(cur - prev >= x){
                placed++;
                prev = cur;
            }
        }
        return placed == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans=0, n = position.size();
        sort(position.begin(),position.end());
        int low=1,high = ceil(position[n-1]/(m-1.0));
        while(low<=high){
            int mid = low + (high-low)/2;
            if(place(position,mid,m)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};