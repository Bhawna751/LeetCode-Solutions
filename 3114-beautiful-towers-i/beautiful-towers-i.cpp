#define ll long long
class Solution {
public:
    ll maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,n);
        vector<ll>leftsum (n,0), rightsum(n,0);
        leftsum[0]=heights[0];
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()){
                ps[i]=st.top();
            }
            int prev =  ps[i];
            int cnt=i-prev;
            leftsum[i] += (ll) cnt*heights[i];
            if(prev!=-1){
                leftsum[i] += leftsum[prev];
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(n-1);
        rightsum[n-1]=heights[n-1];
        for(int i =n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
            if(!st.empty()) ns[i]=st.top();
            int next = ns[i];
            int cnt = next-i;
            rightsum[i] += (ll) cnt*heights[i];
            if(next!=n) rightsum[i] += rightsum[next];
            st.push(i); 
        }
        ll maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, leftsum[i] + rightsum[i] - heights[i]);
        }
        return maxi;
    }
};