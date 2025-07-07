class Solution {
public:
    
    static bool cmp(const vector<int>& x, const vector<int>& y)
    {
        return x[1] < y[1];
    }
    
    int find(int x, vector<int>& f)
    {
        if(f[x] == x)
            return x; 
        else 
            return f[x] = find(f[x], f); 
    }
    
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end(), cmp);
        vector<int> f;  
        
        int n = events[events.size()-1][1], ans = 0; 
        for(int i=0;i<=n+1;i++)
            f.push_back(i); 
        
        for(auto it:events)
        {
            int x = find(it[0], f); 
            if(x <= it[1])
            {
                ans++; 
                f[x] = find(x+1, f); 
            }
        }
        
        return ans; 

    }
};