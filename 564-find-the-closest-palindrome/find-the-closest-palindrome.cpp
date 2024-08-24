class Solution {
public:
    
    long long next(long long n){
        long long l=0,r=n, ans=-1e9;
        while(l<=r){
            long long mid = (r-l)/2 + l;
            long long palin = convert(mid);
            if(palin < n){
                ans = palin;
                l = mid+1;
            }
            else r = mid - 1;
        }
        return ans;
    }
    long long prev(long long n){
        long long l=n,r=1e18, ans=-1e9;
        while(l<=r){
            long long mid = (r-l)/2 + l;
            long long palin = convert(mid);
            if(palin > n){
                ans = palin;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    long long convert(long long &n){
        string s = to_string(n);
        int len = s.length();
        int l = (len-1)/2, r = len/2;
        while(l>=0){
            s[r++] = s[l--];
        }
        return stoll(s);
    }
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        long long a = next(num);
        long long b = prev(num);
        if(abs(a-num) <= abs(b-num)) return to_string(a);
        return to_string(b);
    }
};