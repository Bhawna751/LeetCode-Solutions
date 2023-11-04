class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()<=0||matrix[0].size()<=0) return 0;
        int n=matrix[0].size()+1;
        int m=matrix.size();
        int t=0,w=0,r=0;
        vector<int> h (n,0);
        for(int i=0;i<m;i++){
            stack<int>s;
            for(int j=0;j<n;j++){
                if(j<n-1){
                    if(matrix[i][j]=='1') h[j]+=1;
                    else h[j]=0;
                }
                while(!s.empty()&&h[s.top()]>=h[j]){
                    t=h[s.top()];
                    s.pop();
                    w=s.empty()?j:j-s.top()-1;
                    if(t*w>r) r=t*w;
                }
                s.push(j);
            }
        }
        return r;
    }
};