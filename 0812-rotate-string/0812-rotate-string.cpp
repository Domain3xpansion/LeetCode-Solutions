class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        string res = s+s;
        if (res.find(goal) != string::npos) {
            return true;
        } else {
            return false;
        }
    }
};