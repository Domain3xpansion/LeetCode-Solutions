class Solution {
public:
    int ib(int n, vector<int>& dp){
        if(n == 1)   // base case because you cant break 1 into anything
            return 1;
        if(dp[n] != -1)
            return dp[n];
        for(int i=1; i<n; i++){ // i<n because for n = 4, you can break it to 1*3, 2*2 and //3*1 where i reps left operand. If i<=n, then 4*0 will make product = 0
            int prod = i * max(ib(n-i, dp), n-i);
            /*
            Idea behind max(ib) = when you split n-i, the result may not yield better answer.
            For example n = 5, you have broken it into 2 and 3. You can keep 3 as it is OR break it further. If you keep it, 2*3 = 6 and if you break 3 into 1 * 2 then 2 * 1 * 2 = 4. But, 6 > 4 thats why max
              n-i
               |
       âââââââââ´ââââââââ
       â               â
   keep it          break it
   n-i              ib(n-i)

       âââââââââ¬ââââââââ
               â
              max*/
            dp[n] = max(prod, dp[n]); 
        }
        return dp[n];
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return ib(n, dp);
    }
};