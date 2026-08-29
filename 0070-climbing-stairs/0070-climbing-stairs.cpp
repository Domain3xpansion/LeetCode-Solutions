class Solution {
public:
    int climbStairs(int n) {
        // using Top Down approach
        static int arr[46] = {0};
        if (n <= 2)
            return n;
        if(arr[n] != 0)
            return arr[n];
        arr[n] = climbStairs(n-1) + climbStairs(n-2);
        return arr[n];
    }
};