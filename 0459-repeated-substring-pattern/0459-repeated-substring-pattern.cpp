class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string res = "";
        int n = s.size();
        for(int i=1; i<=n/2; i++){
            res = "";
            if(n%i==0){
                int into = n/i;
                string ss = s.substr(0, i);
                while(into--){
                    res.append(ss);
                }
            }
            if(res == s)
                return true;
        }
        return false;
    }
};