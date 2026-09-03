class Solution {
public:
    int solveTD(vector<int> samecoins, int amt, vector<int>& dp){
        if(amt == 0)
            return 0;
        if(dp[amt] != -1)
            return dp[amt];
        int ncoins = INT_MAX;
        for(int c : samecoins){
            if(c<=amt){
                int res = solveTD(samecoins, amt - c, dp);
                if(res != INT_MAX)
                    ncoins = min(ncoins, 1 + res);
            }
        }
        return dp[amt] = ncoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        if(solveTD(coins, amount, dp) == INT_MAX)
            return -1;
        else
            return solveTD(coins, amount, dp);
    }
};