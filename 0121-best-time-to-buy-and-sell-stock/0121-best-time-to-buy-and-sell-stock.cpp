class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, cost = 0, mincost = prices[0];
        for(int i=1; i<=prices.size()-1; i++){
            mincost = min(mincost, prices[i]);
            cost = prices[i] - mincost;
            profit = max(profit, cost);
        }
        return profit;
    }
};
        
        
        
        
        
        
        
        
        
        
        
        
        /*int profit = 0, minimum = prices[0], max_profit = 0;
        for(int i=1; i<prices.size(); i++){   //starting from 1 because cant sell the stock on the same day
            profit = prices[i] - minimum;
            minimum = min(minimum, prices[i]);
            if(profit > max_profit)
                max_profit = profit;
        }
        return max_profit;*/
    /*}
};*/