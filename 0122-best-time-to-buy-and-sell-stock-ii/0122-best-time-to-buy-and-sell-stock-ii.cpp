class Solution {
public:
    int buysell(int i, int buy, vector<int>& arr, vector<vector<int>>& dp){
        if(i == arr.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if(buy){  // If we are buying, we have 2 options -> buy or not buy
            profit = max(-arr[i] + buysell(i+1, 0, arr, dp), 0 + buysell(i+1, 1, arr, dp)); 
        }else{ // If we are selling, we have 2 options -> sell or not sell
            profit = max(arr[i] + buysell(i+1, 1, arr, dp), 0 + buysell(i+1, 0, arr, dp));
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return buysell(0, 1, prices, dp);
    }
};