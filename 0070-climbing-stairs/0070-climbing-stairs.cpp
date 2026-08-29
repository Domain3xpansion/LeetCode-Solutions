class Solution {
public:
    int climbStairs(int n) {
        // using Top Down approach
        /* Two learnings while implementing Top Down approach:
            1. use static. Because, memoization is not actually being preserved between recursive calls. If static keyword is not used, arr[n] is always 0 when a new function call starts, causing exponential recursion â TLE.
            2. declared arr of 45 cells, should be 46 */
        static int arr[46] = {0};
        if (n <= 2)
            return n;
        if(arr[n] != 0)
            return arr[n];
        arr[n] = climbStairs(n-1) + climbStairs(n-2);
        return arr[n];
    }
};