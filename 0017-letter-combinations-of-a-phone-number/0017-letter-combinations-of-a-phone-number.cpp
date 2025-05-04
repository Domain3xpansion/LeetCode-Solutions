class Solution {
public:
    const vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> helper(string p, string up){
        if(up.empty()){
            vector<string> l;
            l.push_back(p);
            return l;
        }
        int digit = up[0] - '0';
        string letter = mapping[digit];
        vector<string> list;
        for(char ch : letter){
            vector<string> subl = helper(p+ch, up.substr(1));
            list.insert(list.end(), subl.begin(), subl.end());
        }
        return list;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string p;
        return helper(p, digits);
    }
};