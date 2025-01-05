class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        new_s = ''.join([char for char in s if char.isalnum()])
        reversed_s = new_s[::-1]
        if(reversed_s == new_s):
            return True
        else:
            return False
        