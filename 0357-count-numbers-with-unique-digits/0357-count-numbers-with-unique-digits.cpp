class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        int num = 10, unique_per_digit = 9, remaining = 9;
        /* unique_per_digit = 9 because for leftmost digit of any number, that digit will have 9 choices => 1 to 9 (why not zero? because a number cant start with 0)
        As we keep coming towards the right side, the no of choices will keep decreasing.
        Lets take a 4 digit number as an example:
        no of choices = 9 * 9(because 0 to 9 that makes it 10 but 1st and 2nd digit cant be same) * 8(also 0 to 9 which makes it 10 but 3rd digit cant be equal to 1st and 2nd) * 7(yk the reason) */
        for(int i=2; i<=n; i++){
            unique_per_digit *= remaining;
            num += unique_per_digit;
            remaining--;
        }
        return num;
    }
};