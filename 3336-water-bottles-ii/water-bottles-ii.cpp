class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        for(int i=numBottles;i>=numExchange;numExchange++){
            ans++;
            i = i - (numExchange-1);
        }
        return ans;
    }
};