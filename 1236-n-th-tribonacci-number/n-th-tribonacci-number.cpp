class Solution {
public:
    int tribonacci(int n) {
        int tn=0,tn1=1,tn2=1,tn3;
        if(n<2)return n;
        while(n-- > 2){
            tn3= tn+tn1+tn2;
            tn = tn1;
            tn1 = tn2;
            tn2 = tn3; 
        }
        return tn2;
    }
};