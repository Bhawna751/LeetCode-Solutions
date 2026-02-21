class Solution {
public:
    bool checkPrime(int x){
        if(x<=1)return false;
        if(x==2 || x==3) return true;
        if(x%2 ==0 || x%3==0) return false;
        for(int i=5;i*i<=x; i += 6){
            if(x%i==0 || x%(i+2)==0) return false;
        }
        return true;

    }
    int cntSet(int x){
        int cnt=0;
        while(x>1){
            cnt = cnt+ (x&1);//2
            x = x>>1;//101->001
        }
        if(x==1)cnt++;
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int x=0;
        for(int i=left;i<=right;i++){
            int setbit = cntSet(i);//stbit = 2
            if(checkPrime(setbit)) x++;
        }
        return x;
    }
};