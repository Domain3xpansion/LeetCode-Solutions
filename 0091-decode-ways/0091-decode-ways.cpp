class Solution {
public:
    // Top Down approach
    int solveTD(string &s, int pos, vector<int>& dp){
        if(pos == s.size())
            return 1;
        if(s[pos] == '0')
            return 0;
        if(dp[pos] != 0)
            return dp[pos];
        int ways = solveTD(s, pos+1, dp);
        if(pos+1 < s.size()){
            string two = s.substr(pos, 2);
            if(two >= "10" && two <= "26")
                ways += solveTD(s, pos + 2, dp);
        }
        dp[pos] = ways;
        return dp[pos];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        return solveTD(s, 0, dp);
    }
};