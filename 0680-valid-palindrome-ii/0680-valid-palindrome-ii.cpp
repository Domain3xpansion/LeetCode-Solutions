class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        int left = l;
        int right = r;
        while(left<right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        // brute force
        /*for(int i=0; i<s.size(); i++){
            string newstr = "";
            for(int k=0; k<s.size(); k++){
                if(k != i)
                    newstr += s[k];
            }
            string rev = newstr;
            reverse(rev.begin(), rev.end());
            if(rev == newstr)
                return true;
        }
        return false;*/

        // optimal approach
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l] != s[r])
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            l++;
            r--;
        }
        return true;
    }
};