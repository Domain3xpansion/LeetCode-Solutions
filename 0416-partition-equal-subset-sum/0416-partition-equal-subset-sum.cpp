class Solution {
public:
    /* No DP
    bool pess(vector<int>& arr, int pos, int target){
        if(target == 0)
            return true;
        if(pos >= arr.size())
            return false;
        bool take = false;
        bool notTake = pess(arr, pos + 1, target);
        if(arr[pos] <= target)
            take = pess(arr, pos + 1, target - arr[pos]); 
        return take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        return pess(nums, 0, target);
    }
    */

    // Top down DP
    bool pess(vector<int>& arr, int pos, int target, vector<vector<int>>& dp){
        if(target == 0)
            return true;
        if(pos >= arr.size())
            return false;
        if(dp[pos][target] != -1)
            return dp[pos][target];
        bool take = false;
        bool notTake = pess(arr, pos + 1, target, dp);
        if(arr[pos] <= target)
            take = pess(arr, pos + 1, target - arr[pos], dp); 
        dp[pos][target] = take || notTake;
        return dp[pos][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return pess(nums, 0, target, dp);
    }
};