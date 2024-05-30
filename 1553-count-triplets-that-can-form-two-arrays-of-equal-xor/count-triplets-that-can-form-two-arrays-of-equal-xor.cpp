class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();//2 3 1 6 7
        int cnt=0;

        for(int i=0;i<n-1;i++){//0-->3 3
            int curxor=0;//curxor = 6
            for(int k=i;k<n;k++){//4-->4 4
                curxor ^= arr[k];// curxor = 1^ = 2
                if(curxor == 0) cnt += k-i;//cnt = 2
            }
        }
    //1 0
    //0 1
    //0 0 

        return cnt;
    }
};