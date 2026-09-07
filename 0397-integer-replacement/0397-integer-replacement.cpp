class Solution {
public:
    int solve(unordered_map<long long, int>& dp, long long n){
        if(n == 1)  // Base case
            return 0;
        if(dp.count(n))
            return dp[n];
        if(n%2 == 0)
            dp[n] = 1 + solve(dp, n/2);
        else
            dp[n] = 1 + min(solve(dp, n-1), solve(dp, n+1));
        return dp[n];
    }
    int integerReplacement(int n) {
        unordered_map<long long, int> um;
        return solve(um, n);
    }
};