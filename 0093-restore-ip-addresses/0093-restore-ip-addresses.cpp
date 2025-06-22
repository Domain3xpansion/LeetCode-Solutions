class Solution {
public:
    bool isValid(string str){
        if(str[0] == '0' && str.size() > 1)
            return false;
        int val = stoi(str);
        return val <= 255;
    }

    void solve(string &s, int index, int parts, string curr, vector<string> &ans, int n){
        if(parts == 4 && index == n){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(index + 1 <= n)
            solve(s, index + 1, parts + 1, curr + s.substr(index, 1) + ".", ans, n);
        if(index + 2 <= n && isValid(s.substr(index, 2)))
            solve(s, index + 2, parts + 1, curr + s.substr(index, 2) + ".", ans, n);
        if(index + 3 <= n && isValid(s.substr(index, 3)))
            solve(s, index + 3, parts + 1, curr + s.substr(index, 3) + ".", ans, n);
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if(n>12)
            return {};
        vector<string> ans;
        int parts = 0;
        string curr = "";
        solve(s, 0, parts, curr, ans, n);
        return ans;
    }
};