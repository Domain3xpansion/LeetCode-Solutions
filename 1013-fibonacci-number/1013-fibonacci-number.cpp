class Solution {
public:
    int solve(int n, vector<int>& dp){ 
        if(n <= 1) 
            return n; 
        if(dp[n] != 0) 
            return dp[n]; 
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp); 
        return dp[n]; 
    }
    
    int fib(int n){
        //Top down approach
        vector<int> dp(n+1, 0); 
        return solve(n, dp);

        // Bottom up approach
        /*
        if(n==0)
            return 0;    
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];*/
    }
};