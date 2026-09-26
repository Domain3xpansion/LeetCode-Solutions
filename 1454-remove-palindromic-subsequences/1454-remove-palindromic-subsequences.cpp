class Solution {
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int removePalindromeSub(string s) {
        /*Key observation is that because the string contains only a and b, the answer can only be 0, 1, or 2:
        1. If s is empty -> 0
        2. If s is already a palindrome -> 1
        3. If s is not palindrome -> 2
        (because s is comprised of a and b. It doesn't matter whether no of a's is odd/even and no of b's is odd/even. We can chose all a's as one subsequence and it will be palindrome. So, steps = 1. After removing a's, we're left with b's. That subsequence will also be palindrome in nature. So, steps = 2.
        Take examples like "abb" = "a" + "bb", "baabb" = "bbb" + "aa")*/

        if(s.empty())
            return 0;
        if(isPalindrome(s))
            return 1;
        return 2;
    }
};