class Solution {
public:
    /*Top down approach
    Time complexity
    O(n*m)
    Space complexity
    O(n*sum)(for 2D DP vector) + O(n)(for recursion stack) => O(n*sum) + O(n) => O(n*sum)*/
    int ts(vector<int>& nums, int pos, int target, int sum, vector<vector<int>>& dp){
        if(pos == nums.size()){
            if(target == 0)
                return 1;
            else
                return 0;
        }
        int adjustedtarget = target + sum;
        /*Shift target by sum so that negative target values can be mapped to valid
        non-negative DP indices. For example, target -5 -> index 0, target 0 -> index 5,
        and target +5 -> index 10.*/
        if(adjustedtarget < 0 || adjustedtarget >= 2*sum + 1)
            return 0;
        if(dp[pos][adjustedtarget] != -1)
            return dp[pos][adjustedtarget];
        int postake = 0, negtake = 0;
        postake = ts(nums, pos + 1, target - nums[pos], sum, dp);
        negtake = ts(nums, pos + 1, target - (-nums[pos]), sum, dp);
        dp[pos][adjustedtarget] = postake + negtake;
        return dp[pos][adjustedtarget]
;    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        /* calculating sum because we need to know how many columns will be there in the 2D DP vector. Whatever sum is, make twice of it(1/2 for -ve target values and 1/2 for +ve target values)*/
        vector<vector<int>> dp(n+1, vector<int>(2*sum + 1, -1));
        /* +1 because zero itself is one of the possible target values.
        For sum = 5, that's:
        -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5*/
        return ts(nums, 0, target, sum, dp);
    }
};