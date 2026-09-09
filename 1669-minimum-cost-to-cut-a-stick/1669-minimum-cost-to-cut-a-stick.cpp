class Solution {
public:
/* TC = O(m^3)
SC = O(m^2) because map stores at most O(m^2) states. Map stores only the states that are actually calculated.
Number of states: O(m2)
recursion stack:O(m)
So, SC = O(m^2+m) = O(m^2)*/
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


/*
class Solution {
public:
    int solvetd(int l, int r, vector<vector<int>>& dp, vector<int>& cuts){
        if(dp[l][r] != -1)
            return dp[l][r];
        int cost = INT_MAX;
        for(int x : cuts){
            if(l < x && x < r)
                cost = min(cost, (r-l) + solvetd(l, x, dp, cuts) + solvetd(x, r, dp, cuts));
        }
        if(cost == INT_MAX)
            cost = 0;
        dp[l][r] = cost;
        return dp[l][r];
    }

    int minCost(int n, vector<int>& cuts){
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solvetd(0, n, dp, cuts);
    }
};

TC
For example:         n = 10 and cuts = [2, 4, 7]
Let m = no of cuts. Although the DP table has n^2 cells, I am not using all those cells.
The values of l and r come from:
0
cuts[0]
cuts[1]
...
cuts[m-1]
n
For m cuts, there are m+2 possible boundary positions.

possible boundaries are: 0, 2, 4, 7, 10
So, possible states are: 
(0,2)
(0,4)
(0,7)
(0,10)
(2,4)
(2,7)
(2,10)
(4,7)
(4,10)
(7,10) = 10 states
That's equal to O(m+2)^2 states = O(m^2) states

Now, there is a for loop. For every state, we are accessing all the elements in cuts vector. That's 'm' work. So, TC = O(m^2) * O(m) = O(m^3)
But there is 2D DP also. For that, TC = O(n^2)
So, total TC = O(n^2) + O(m^3) = O(n^2 + m^3)

SC = O(n^2) + O(m)(for recursion stack) = O(n^2) because the DP table itself has 2^n where n = length of stick

Memory Limit Exceeded
74 / 101 testcases passed
Last Executed Input
Use Testcase
n =
6448
cuts =
[3309,5839,4626,4670,5971,6426,5561,2835,3474,3539,1880,4123,571,3128,4075,5896,5020,207,3529,5435,2440,3993,5885,2145,2422,3379,949,248,2627,3392,1795,4893,4415,3282,1776,5520,2199,57,3098,968,1310,4870,5503,1336,636,4747,1371,854,2882,5976,5409,3173,5256,4960,2662,508,1625,304,5867,5939,2499,2845,744,6252,5320,3552,4790,6112,3535,4783,6194,4248,1886,3264,3221,407,1954,1731,3318,6213,1299,5206,3753]
*/