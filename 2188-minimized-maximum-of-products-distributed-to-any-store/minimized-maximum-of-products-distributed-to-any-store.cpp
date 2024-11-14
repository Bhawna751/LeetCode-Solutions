class Solution {
public:
    bool check(int x, vector<int>&quantities, int n){
        int j=0;
        int rem=quantities[j];
        for(int i=0;i<n;i++){
            if(rem<=x){
                j++;
                if(j==quantities.size())return true;
                else rem=quantities[j];
            }else{
                rem = rem-x;
            }
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1, r = *max_element(quantities.begin(), quantities.end());
        while(l<r){
            int mid = (l+r)/2;
            if(check(mid,quantities,n))r=mid;
            else l=mid+1;
        }
        return l;
    }
};