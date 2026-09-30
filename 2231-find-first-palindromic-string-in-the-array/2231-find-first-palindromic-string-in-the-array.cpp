class Solution {
public:
    bool isPalindrome(string newstr){
        int left = 0;
        int right = newstr.length() - 1;
        while(left<right){
            if(newstr[left] != newstr[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            if(isPalindrome(s))
                return s;
        }
        return "";
    }
};