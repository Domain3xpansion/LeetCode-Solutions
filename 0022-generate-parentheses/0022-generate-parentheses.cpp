class Solution {
public:
    void genParen(int n, int oc, int cc, string &ds, vector<string> &result){
        if(ds.length() == 2*n){
            result.push_back(ds);
            return;
        }
        if(oc < n){
            ds.push_back('(');
            genParen(n, oc+1, cc, ds, result);
            ds.pop_back();
        }
        if(cc < oc){
            ds.push_back(')');
            genParen(n, oc, cc+1, ds, result);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int opencount = 0, closecount = 0;
        string ds = "";
        vector<string> result;
        genParen(n, opencount, closecount, ds, result);
        return result; 
    }
};