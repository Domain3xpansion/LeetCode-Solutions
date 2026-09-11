class Solution {
public:
    /*Top down approach
    T.C = O(n^2)
    1. O(n) for the n states(from dp[0] to dp[n]) and O(n) for the for loop
    2. O(n) * O(n) = O(n^2)
    S.C = O(n)
    1. O(n) for the dp vector
    2. O(n) for the recursion stack in worst case*/

    int solvetd(vector<int>& dp, int n){  // n = no of nodes required to construct a BST.
        if(n <= 1) 
            return 1;
        /*If n == 0, ans is 1 because there is only one BST = empty tree
        If n == 1, ans is also 1 because there is only one BST = the node itself*/
        if(dp[n] != -1)
            return dp[n];
        int num = 0;
        for(int k = 1; k<=n; k++){  // trying every possible node 'k' as the root node
            num += solvetd(dp, k-1) * solvetd(dp, n-k);
            /*why *? because whatever is the no of left subtrees are there, all of them will combine with all of the right subtrees to form a unique BST. It's like combining shirts with pants. If you have 2 shirts and 3 pants, you can take shirt A and wear with all 3 pants to form a pair. Similarly, you can take shirt B and wear with all 3 pants to form a pair. So, 2 * 3 = 6 pairs */
        }
        dp[n] = num;
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solvetd(dp, n);
    }
};