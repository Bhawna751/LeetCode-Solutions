class Solution {
public:
    int mod=1e9+7;

    int numberOfWays(string s) {
        
        int n=s.size();
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='S')
             c++;
        }
        if(c==0 || c%2 != 0)
          return 0;
        if(c==2)
          return 1;
        
        long ans=1; 
        int seat=0; 
        int plant=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='S')
            {
                seat++;
            }
            
            else if(seat>=2 && (seat%2)==0) 
            {
                
                plant++;
            }
            
            if(seat > 2 && seat%2 != 0 && plant > 0)
            {
                ans=((ans%mod)*((plant+1)%mod))%mod;
                plant=0;
            }
        }
        return (int)ans;
    }
};