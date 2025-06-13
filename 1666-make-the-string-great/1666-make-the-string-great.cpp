class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string res = "";
        for(int i=0; i<=n-1; i++){
            if(!res.empty() && s[i] != res.back() && tolower(s[i]) == tolower(res.back()))
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        return res;
    }
};