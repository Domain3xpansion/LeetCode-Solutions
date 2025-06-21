class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size(), i=0;
        string res1 = "", res2 = "";
        while(i<n){
            if(s[i]!='#')
                res1.push_back(s[i]);
            else if(!res1.empty())
                res1.pop_back();
            i++;
        }
        i=0;
        while(i<m){
            if(t[i]!='#')
                res2.push_back(t[i]);
            else if(!res2.empty())
                res2.pop_back();
            i++;
        }
        return res1 == res2;
    }
};