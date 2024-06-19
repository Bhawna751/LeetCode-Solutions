// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right = n;// left = 1 right = 5
        while(left < right){
            int mid = left + (right - left) / 2;//mid = 1 + 2 = 3
            if(isBadVersion(mid)) right = mid;
            else left = mid + 1; 
        }
        return left;
    }
};