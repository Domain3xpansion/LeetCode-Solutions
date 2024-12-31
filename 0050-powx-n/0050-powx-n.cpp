class Solution {
public:
    double myPow(double x, int n) {
        long long copy = n;
        copy = llabs(copy);
        /*
        copying 'n' in 'copy' because 8^-34 = 1/8^34 so, if n is negative, we can evaluate it 
        by evaluating the expression as if n was positive and later check, if 'n' is negative, we 
        can return 1/value of expression if n was positive*/
        if(copy==0)
            return 1;
        double extra = 1;
        while(copy>=1){
            /*
        for example, 8^35
        35 is odd, so
             we can multiply 8 with a variable which has 1 by default
        and, reduce the value of n, making evaluation easier.
        Now that n = 34, we can write it 8^34 as (8)^2*17 = (8^2)^17 = 64^17
        and it keeps on going until loop fails */
            if(copy%2==1){
                extra = extra * x;
                copy = copy - 1;
            }
            copy = copy/2;
            x = x * x;
        }
        if(n<0)
            return 1/extra;
        return extra;
    }
};