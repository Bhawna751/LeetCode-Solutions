class Solution {
public:
    int bs(vector<vector<int>> &items, int target){//target = 1
        int left = 0, right = items.size()-1;
        int maxi =0;
        while(left<=right){
            int mid = (left+right)/2;// mid = 0
            if(items[mid][0] > target)right=mid-1;//right = 1
            else{
                maxi = max(maxi,items[mid][1]);//maxi = 2
                left = mid+1;//left = 1
            }
        }
        return maxi;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();//items = [[1,2],[2,4],[3,4],[3,5],[5,6]], queries = [1,2,3,4,5,6]
        vector<int> ans(n);//
        sort(items.begin(), items.end());
        int maxi = items[0][1];// maxi = 6
        for(int i=0;i<items.size();i++){
            maxi  = max(maxi, items[i][1]);
            items[i][1] = maxi;
        }
        for(int i=0;i<n;i++){
            ans[i]=bs(items,queries[i]);// 2,
        }
        return ans;
    }
};