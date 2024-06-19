class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left = 1, right = 1e9;
        while(true){
            int mid = left + (right - left) /2;// mid = 1 + 3 = 4
            if(mid > x/mid){// 4 > 2
                right = mid - 1; // right = 3
            }
            else{
                if(mid + 1 > x/(mid+1)) return mid; // 
                left = mid + 1;
            }
        }
    }
};