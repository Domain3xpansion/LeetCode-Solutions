class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), i=0;
        int m = t.size(), j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return m-j;
    }
};