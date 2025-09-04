class Solution {
public:
    int findClosest(int x, int y, int z) {
     int diff1 = abs(z-x);
     int diff2 = abs(z-y);
     if(diff1 > diff2) return 2;   
     else if(diff1 < diff2) return 1;
     else return 0;
    }
};