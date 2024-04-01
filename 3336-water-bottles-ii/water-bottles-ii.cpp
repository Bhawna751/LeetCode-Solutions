class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=0,drunk=0;
        while(numBottles>0 || empty>=numExchange){
            if(empty>=numExchange){
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
            drunk += numBottles;
            empty += numBottles;
            numBottles=0;
        }
        return drunk;
    }
};