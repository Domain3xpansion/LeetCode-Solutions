class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j=n-1;
        while(i<j){
            if(!isVowel(s[i]))
                i++;
            if(!isVowel(s[j]))
                j--;
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};