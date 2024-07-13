class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ind(n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(),
            [&](int l, int r){
                return positions[l]<positions[r];
            });
        stack<int> st;
        for (int it : ind) {
            if (directions[it] == 'R')
                st.push(it);
            else {
                while (!st.empty() && healths[it] > 0) {
                    int top = st.top();
                    st.pop();
                    if (healths[top] > healths[it]) {
                        healths[top]--;
                        healths[it] = 0;
                        st.push(top);
                    } else if (healths[top] < healths[it]) {
                        healths[it]--;
                        healths[top] = 0;
                    } else {
                        healths[top] = 0;
                        healths[it] = 0;
                    }
                }
            }
        }
        for(int ind = 0;ind<n;ind++){
            if(healths[ind] > 0){
                ans.push_back(healths[ind]);
            }
        }
        return ans;
    }
};