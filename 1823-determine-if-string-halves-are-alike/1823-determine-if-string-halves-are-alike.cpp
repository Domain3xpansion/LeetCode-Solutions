class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int n2 = n/2;
        int i=0, j=n2;
        int v1=0, v2=0;
        while(i<n/2 && j<n){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                v1++;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')
                v2++;
            i++;
            j++;
        }
        if(v1 == v2)
            return true;
        return false;
    }
};