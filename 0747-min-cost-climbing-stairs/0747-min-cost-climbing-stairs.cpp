class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Bottom up approach
       cost.push_back(0);
       int n = cost.size();
       for(int i = n-3; i >= 0; i--){
            cost[i] = min(cost[i] + cost[i+1], cost[i] + cost[i+2]);
       }
       /*
       cost[i] + cost[i+1] = Pay for step i, then take 1 step from i and pay it's cost too. cost[i+1] represents the minimum cost from step i+1 all the way to the top, not merely the original price of that step.

       cost[i] + cost[i+2] = Pay the cost of step i, then take 2 steps, and from there follow the cheapest possible path to the top.
       */
       return min(cost[0], cost[1]);
    }
};