class Solution {
public:
    bool isPalindrome(int x) {
        // mathematical approach
        /*if(x<0) return false;
        long original = x;
        long rev = 0;
        while(x>0){
            int dig = x % 10;
            rev = (rev * 10) + dig;
            x /= 10;
        }
        return original == rev;*/

        // 2 pointers approach
        if(x < 0) 
            return false;
        string str = to_string(x);
        int left = 0;
        int right = str.length() - 1;
        while(left<right){
            if(str[left] != str[right]){
                return false; // Mismatch found
            }
            left++;
            right--;
        }
        return true;
    }
};