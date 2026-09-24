class Solution {
public:
    bool isPalindrome(int x) {
        // mathematical approach
        if(x<0) return false;
        long original = x;
        long rev = 0;
        while(x>0){
            int dig = x % 10;
            rev = (rev * 10) + dig;
            x /= 10;
        }
        return original == rev;
    }
};