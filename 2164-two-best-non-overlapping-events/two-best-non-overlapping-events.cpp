class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int sum =0;
        
        sort(events.begin(), events.end());//1,3,2   2,4,3    4,5,2
        vector<int> suffix(n,-1);// 3 3 2
        suffix[n-1] = events[n-1][2];

        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1], events[i][2]);
        }

        for(int i=0;i<n;i++){//i = 0
            int l = i+1;//l = 2
            int r = n-1;//r = 1
            int ind = -1;//ind= 2
            while(l<=r){
                int mid = (l+r)/2;//mid = 2
                if(events[mid][0] > events[i][1]){// 4 > 3
                    ind = mid;
                    r = mid-1;
                }
                else l= mid+1;
            }
            if(ind == -1) sum = max(sum, events[i][2]);
            else sum = max(sum, events[i][2] + suffix[ind]);// sum = 2+2
        }
        return sum;
    }
};