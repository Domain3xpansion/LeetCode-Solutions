class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastocc(26, 0);
        vector<bool> taken(26, false);
        string res = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            lastocc[s[i]-'a'] = i;
        }
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(taken[ch-'a']==true)
                continue;
            while(!res.empty() && res.back() > ch && lastocc[res.back()-'a'] > i){
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            taken[ch-'a'] = true;
            res.push_back(ch);
        }
        return res;
    }
};