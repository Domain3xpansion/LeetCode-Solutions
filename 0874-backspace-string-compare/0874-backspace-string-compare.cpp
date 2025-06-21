class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*int n = s.size(), m = t.size(), i=0;
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
        return res1 == res2;*/

        int n = s.size(), m = t.size(), i=n-1, j=m-1;
        int skips = 0, skipt = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    skips++;
                    i--;
                }else if(skips > 0){
                    skips--;
                    i--;
                }else{
                    break;
                }
            }
            while(j >= 0){
                if(t[j] == '#'){
                    skipt++;
                    j--;
                }else if(skipt > 0){
                    skipt--;
                    j--;
                }else{
                    break;
                }
            }
            char si = i < 0 ? '$' : s[i];
            char tj = j < 0 ? '$' : t[j];
            if(si != tj)
                return false;
            i--;
            j--;
        }
        return true;
    }
};