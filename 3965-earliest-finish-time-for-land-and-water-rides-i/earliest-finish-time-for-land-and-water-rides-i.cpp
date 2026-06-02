class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n = lst.size(), m=wst.size();
        int l=1e9, w=1e9,lw=1e9,wl=1e9;
        for(int i=0;i<n;i++){
            l=min(l,lst[i]+ld[i]);
        }
        for(int j=0;j<m;j++){
            w=min(w,wst[j]+wd[j]);
            lw=min(lw,max(wst[j],l)+wd[j]);
        }
        for(int j=0;j<n;j++){
           
            wl=min(wl,max(lst[j],w)+ld[j]);
        }
        return min(lw,wl);
    }
};