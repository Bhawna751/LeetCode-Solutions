class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five =0,ten=0;
        for(int it : bills){
            if(it == 5) five++;
            else if(it == 10)five--, ten++;
            else if(ten>0) ten--,five--;
            else five = five - 3;
            if(five<0) return false;
        }
        return true;
    }
};