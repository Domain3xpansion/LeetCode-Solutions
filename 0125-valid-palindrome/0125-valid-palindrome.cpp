class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        string newstr = "";
        while(s[i] != '\0'){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                newstr += tolower(s[i]);
            i++;
        }
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
};