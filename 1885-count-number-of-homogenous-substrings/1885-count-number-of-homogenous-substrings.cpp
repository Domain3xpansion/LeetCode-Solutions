class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        int n = s.size();
        int i = 0, count = 0, mult;
        while(i<n){
            if(i>0 && s[i]==s[i-1]){
                mult++;
                count = (count + mult) % mod;
            }else{
                count = count + 1;
                mult = 1;
            }
            i++;
        }
        return count%mod;
    }
};