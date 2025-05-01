class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int p, int strength) {
        int n = tasks.size(), m = workers.size();
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int lo = 0, hi = min(m, n);
        int ans;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            bool flag = true;
            multiset<int> st(workers.begin(), workers.end());
            for(int i = mid - 1; i >= 0; i--) {
                auto it = prev(st.end());
                if(tasks[i] <= *it) {
                    st.erase(it);
                } else {
                    auto it = st.lower_bound(tasks[i] - strength);
                    if(it != st.end()) {
                        count++;
                        st.erase(it);
                    } else {
                        flag = false;
                        break;
                    }
                }
                
                if(count > p) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};