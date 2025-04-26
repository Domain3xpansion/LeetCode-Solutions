class Solution {
public:
    /*
    int uniquePathsactual(int i, int j, int m, int n){
        if(i>=m || j>=n) return 0;
        if(i==(m-1) && j==(n-1)) return 1;
        return uniquePathsactual(i+1, j, m, n) + uniquePathsactual(i, j+1, m, n);
    } 
    /*
    int uniquePathsactual(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i>=m || j>=n) return 0;
        if(i==(m-1) && j==(n-1)) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = uniquePathsactual(i+1, j, m, n, dp) + uniquePathsactual(i, j+1, m, n, dp);
    }
    */
    int uniquePaths(int m, int n){
        //vector<vector<int>> dp(m, vector<int>(n, -1));
        //return uniquePathsactual(0, 0, m, n, dp);
        int N = m+n-2, R=n-1;
        double sum = 1;
        for(int i=1; i<=R; i++){
            sum = sum * (N-R+i)/i;
        }
        return sum;
    }
};