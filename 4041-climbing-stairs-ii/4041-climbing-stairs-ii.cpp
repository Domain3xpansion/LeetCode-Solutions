class Solution {
public:
    // Top down approach
    /*vector<int> costs;
    vector<int> dp;

    int solve(int i){
        if(i == 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int minval = INT_MAX;
        if(i-1 >= 0) 
            minval = min(minval, solve(i - 1) + costs[i - 1] + 1);
        if(i-2 >= 0) 
            minval = min(minval, solve(i - 2) + costs[i - 1] + 4);
        if(i-3 >= 0) 
            minval = min(minval, solve(i - 3) + costs[i - 1] + 9);
        dp[i] = minval;
        return dp[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        this->costs = costs;
        dp = vector<int>(n + 1, -1);
        return solve(n);
    }*/

    // Bottom up approach
    int climbStairs(int n, vector<int>& costs) {
        int dp[n+1];
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            int best = INT_MAX;
            if(i-1 >= 0)
                best = min(best, dp[i - 1] + costs[i - 1] + 1);
            if(i-2 >= 0)
                best = min(best, dp[i - 2] + costs[i - 1] + 4);
            if(i-3 >= 0)
                best = min(best, dp[i - 3] + costs[i - 1] + 9);
            dp[i] = best;
        }
        return dp[n];
    }

};