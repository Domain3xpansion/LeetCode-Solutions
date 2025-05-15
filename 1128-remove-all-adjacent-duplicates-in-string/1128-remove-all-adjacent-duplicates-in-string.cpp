class Solution {
public:
    void remDhelper(string &s, int i){
        if(i <= 0) return;  
        if(s[i] == s[i-1]){     // Remove the pair of duplicates
            s.erase(i - 1, 2);
            remDhelper(s, i-1); // After erasing, move back one position to check for new duplicates formed
        }else
            remDhelper(s, i-1);      // No duplicate at this position, move to the previous character
    }
    string removeDuplicates(string s) {
        if(s.empty()) 
            return "";
        remDhelper(s, s.length() - 1);
        return s;
    }
};