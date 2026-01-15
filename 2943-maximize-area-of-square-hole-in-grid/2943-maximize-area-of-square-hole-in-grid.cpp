class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmaxi = 1;
        
        int curr = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == (hBars[i - 1] + 1)) {
                curr++;
            } else {
                curr = 1;
            }
            hmaxi = max(hmaxi, curr);
        }
        int hGap = hmaxi + 1;
        int vmaxi = 1;
        curr = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == (vBars[i - 1] + 1)) {
                curr++;
            } else {
                curr = 1;
            }
            vmaxi = max(vmaxi, curr);
        }
        int vGap = vmaxi + 1;
        int side = min(hGap, vGap);
        long long area =
            1LL * side * side; 
        return area;
    }
};