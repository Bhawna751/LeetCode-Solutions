class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int two=0,three=0,five=0, nextTwo=2,nextThree=3, nextFive=5;
        for(int i=1;i<n;i++){
            int next = min(nextTwo,min(nextThree,nextFive));
            ugly[i]=next;
            if(next == nextTwo){
                two++; 
                nextTwo = ugly[two] * 2;
            }
            if(next == nextThree){
                three++; 
                nextThree = ugly[three] * 3;
            }
            if(next == nextFive){
                five++; 
                nextFive = ugly[five] * 5;
            }
        }
        return ugly[n-1];
    }
};