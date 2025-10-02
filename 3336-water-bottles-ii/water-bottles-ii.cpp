class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // 'ans' stores the total number of bottles drunk. Initially, it's the number of full bottles you start with.
        int ans = numBottles;
        // 'emptyBottles' is the number of empty bottles you have to exchange.
        int emptyBottles = numBottles;
        
        // Loop as long as you have enough empty bottles to perform an exchange.
        while (emptyBottles >= numExchange) {
            // 1. Perform the exchange: numExchange empty bottles for 1 new full bottle.
            // Update empty bottles: decrease by numExchange, increase by 1 (the new bottle, once drunk).
            emptyBottles = emptyBottles - numExchange + 1;
            
            // 2. The exchange rate increases by 1 for the next exchange.
            numExchange++;
            
            // 3. You drink the new full bottle (added in the emptyBottles update), so increment the total drunk count.
            ans++;
        }
        
        return ans;
    }
};