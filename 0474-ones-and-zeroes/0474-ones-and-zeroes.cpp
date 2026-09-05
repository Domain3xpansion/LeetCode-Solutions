class Solution {
public:
    int oaz(vector<string>& strss, int pos, int m, int n, vector<vector<vector<int>>>& dp){
        if(pos == strss.size())
            return 0;
        if(dp[pos][m][n] != -1)
            return dp[pos][m][n];
        int noofzeroes = count(strss[pos].begin(), strss[pos].end(), '0');
        int noofones  = strss[pos].size() - noofzeroes;
        int take = INT_MIN;
        if(noofzeroes <= m and noofones <= n)
            take = 1 + oaz(strss, pos+1, m - noofzeroes, n - noofones, dp);
        int notTake = oaz(strss, pos+1, m, n, dp);
        dp[pos][m][n] = max(take, notTake);
        return dp[pos][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n + 1, -1)));
        return oaz(strs, 0, m, n, dp);
    }
};