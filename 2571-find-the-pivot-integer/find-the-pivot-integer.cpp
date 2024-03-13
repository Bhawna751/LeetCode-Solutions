class Solution {
public:
    int pivotInteger(int n) {
        int left=1,right=n,sum=n*(n+1)/2;
        while(left<right){//1<=8
            int mid=(left+right)/2;
            if(mid * mid -sum < 0) left=mid+1;
            else right=mid;
        }
    return left*left-sum==0 ? left : -1;
    }
};