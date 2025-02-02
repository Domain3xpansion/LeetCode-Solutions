class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = (a & b) << 1;   //Here, we are calculating a&b first because if we don't do it first, then
            // we will lose the original value of a because we are storing a^b in a and the original value of a gets 
            // updated with the newly calculated a^b in each iteration
            a = a ^ b;   // this gives us the sum of 2 numbers without considering the carry
            b = carry;
        }
        return a;   // we return that a^b which gets stored in a itself when carry or a&b becomes 0
    }
};