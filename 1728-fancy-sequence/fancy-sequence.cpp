class Fancy {
public:
    const long long mod = 1e9+7;
    vector<long long> sequence;
    long long multFactor=1, add=0;
    
    long long modPow(long long a, long long b){
        long long ans=1;
        while(b){
            if(b&1){
                ans = ans * a % mod;
            }
            a = a*a%mod;
            b = b>>1;    
        }
        return ans;
    }

    long long modInv(long long x){
        return modPow(x, mod-2);
    }

    Fancy() {
    }
    
    void append(int val) {
        long long x = (val-add+mod)%mod;
        x = x*modInv(multFactor)%mod;
        sequence.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        multFactor = (multFactor* m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= sequence.size()) return -1;
        return (sequence[idx] * multFactor % mod +add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */