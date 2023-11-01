class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }
    int primeCount = 0;
		for (int i = 2; i < n; i++) {
			if (isprime[i]) {
				primeCount++;
			}
		}
		return primeCount;
	}
};