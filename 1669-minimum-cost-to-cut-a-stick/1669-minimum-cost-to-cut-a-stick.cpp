class Solution {
public:
    int solvetd(int l, int r, map<pair<int, int>, int>& dp, vector<int>& cuts){
        if(dp.find({l, r}) != dp.end())
            return dp[{l, r}];
        int cost = INT_MAX;
        for(int x : cuts){
            if(l < x && x < r)
                cost = min(cost, (r-l) + solvetd(l, x, dp, cuts) + solvetd(x, r, dp, cuts));
        }
        if(cost == INT_MAX)
            cost = 0;
        dp[{l,r}] = cost;
        return dp[{l,r}];
    }

    int minCost(int n, vector<int>& cuts){
        map<pair<int, int>, int> dp;
        return solvetd(0, n, dp, cuts);
    }
};