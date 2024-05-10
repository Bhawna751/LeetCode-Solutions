class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();//1 2 3 5
        double i=0.0,j=1.0;

        while(i<j){
            double mid = (i+j)/2;//mid = 0.5
            vector<int> cnt = solve(arr,mid);
            if(k<cnt[0]) j=mid;
            else if(k>cnt[0]) i = mid;
            else return {cnt[1],cnt[2]};
        }
        return {};
    }
    vector<int> solve(vector<int> &arr, double target){
        int cnt =0, i=0,n=arr.size(),num = arr[0],den = arr[n-1];
        for(int j=1;j<n;j++){
            while(i<j && arr[i]<=arr[j]*target) i++;
            cnt = cnt+i;
            if(i>0 && arr[i-1] * den>arr[j]*num){
                num = arr[i-1];
                den = arr[j];
            }
        }
        return {cnt,num,den};
    }
};