class Solution {
public:
    /* Top down approach
    T.C = O(n^2) * O(n) = O(n^3)
    O(n^2) states â each state is an interval (i, j)
    For each state, you try O(n) possible k
    S.C = O(n^2) + O(n) = O(n^2)
    O(n^2) because of 2d vector and O(n) for recursion stack*/
    int solvetd(vector<int>& values, vector<vector<int>>& dp, int i, int j){
        if(j - i < 2)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int lowest_score = INT_MAX;
        for(int k = i+1; k<j; k++){
            int score = values[i] * values[j] * values[k] + solvetd(values, dp, i, k) + solvetd(values, dp, k, j);
            lowest_score = min(lowest_score, score);
        }
        dp[i][j] = lowest_score;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solvetd(values, dp, 0, n-1);
    }
};