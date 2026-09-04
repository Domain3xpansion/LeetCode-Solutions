class Solution {
public:
    int numSquares(int n) {
        // Bottom up approach
        // T.C: O(nân)
        // S.C: O(n)
        vector<int> dp(n+1, INT_MAX);
        // dp[i] = least no of perfect squares that sum to i
        dp[0] = 0;
        for(int target=1; target<=n; target++){
            for(int i=1; i*i <= target; i++){
                dp[target] = min(dp[target], 1 + dp[target-i*i]);
            }
        }
        return dp[n];
    }
};