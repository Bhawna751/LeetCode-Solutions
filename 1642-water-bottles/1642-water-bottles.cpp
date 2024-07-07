class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = 0;
        while(numBottles >= numExchange){
            drunk += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }
        return drunk + numBottles;
    }
};