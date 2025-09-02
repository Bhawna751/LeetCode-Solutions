class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n= points.size(), ans=0;
        for(int i=0;i<n;i++){
            auto& a = points[i];
            for(int j=0;j<n;j++){
                vector<int> b = points[j];
                if(i==j || !(a[0] <= b[0] && a[1] >= b[1])) continue;
                if(n==2){
                    ans++;
                    continue;
                }
                bool flag=false;
                for(int k=0;k<n;k++){
                    int xContained=0, yContained=0;
                    if(k==i || k==j)continue;
                    auto& temp = points[k];
                    if(a[0] <= temp[0] && temp[0] <= b[0]) xContained =1;
                    if(a[1] >= temp[1] && temp[1] >= b[1]) yContained =1;
                    if(xContained && yContained){
                        flag=true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        return ans;
    }
};