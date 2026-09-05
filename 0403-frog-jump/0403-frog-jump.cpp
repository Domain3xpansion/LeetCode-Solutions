class Solution {
public:
    // k = previous jump, pos = stone's index where frog is currently at
    bool fj(vector<int>& stones, int pos, int k, unordered_map<int, int>& um, vector<vector<int>>& dp){
        if(pos == stones.size()-1)
            return true;
        if(dp[pos][k] != -1)
            return dp[pos][k];
        for(int jump = k - 1; jump <= k + 1; jump++){
            if(jump <= 0)
                continue;
            int nextStone = stones[pos] + jump;
            if(um.find(nextStone) != um.end()){   
                int nextPos = um[nextStone];
                if(fj(stones, nextPos, jump, um, dp))
                    return dp[pos][k] = 1;
            }
        }
        dp[pos][k] = 0;
        return dp[pos][k];
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        unordered_map<int, int> um;
        for(int i=0; i<stones.size(); i++){
            um[stones[i]] = i;
        }
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size() + 1, -1));
        return fj(stones, 0, 0, um, dp);
    }
};