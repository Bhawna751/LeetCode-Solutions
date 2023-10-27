class Solution {
public:
    int count(vector<int> &a,int pg){
    int st = 1;
    long long pgst=0;
    for(int i =0;i<a.size();i++){
        if(pgst + a[i]<=pg){
            pgst += a[i];
        }
        else{
            st +=1;
            pgst = a[i];
        }

    }
    return st;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n)return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int st = count(arr, mid);
        if (st > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};